#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
 
 
ll N, M, Q;
struct Matrix{
    unsigned long long a[200][200];
    Matrix(){
        memset(a, 0, sizeof a);
    }
    Matrix(int i){
        memset(a, 0, sizeof a);
        loop(i, 200)a[i][i] = 1;
    }
    Matrix operator *(Matrix other){
        Matrix res = Matrix();
        loop(i, 200){
            loop(k, 200){
                loop(j, 200){
                    res.a[i][k] += a[i][j] * other.a[j][k];
                    res.a[i][k] %= mod;
                }
            }
        }
        return res;
    }
};
 
 
struct Query{
    ll node1;
    ll node2;
    ll k;
    Query(ll _a, ll _b, ll _k){
        node1 = _a;
        node2 = _b;
        k = _k;
    }
 
 
    bool operator<(Query other) const
    {   
        if(k == other.k){
            if(node1 == other.node1){
                return node2 < other.node2;
            }
            return node1 < other.node1;
        }
        return k < other.k;
    }
 
};

void printMatrix(Matrix m){
    loop(i, 3){
        loop(j, 3){
            cout << m.a[i][j] << "|";
        }
        cout << endl;
    }
}
 
Matrix fastPow(Matrix m, ll exp){
    Matrix res = Matrix(1);//Identity Matrix
    while(exp){
        if(exp%2){
            res = m*res;
        }
        m = m*m;
        exp /= 2;
    }
    return res;
}
 

void solve(){
 
    map<ll, Matrix> diffMatrix;
    map<ll, Matrix> diffdiffMatrix;

    map<Query, ll> answers;
 
    cin >> N >> M >> Q;
 
    //sestavimo base
    Matrix base = Matrix();
    
 
    loop(i, M){
        ll a, b;
        cin >> a >> b;
        base.a[--a][--b] = 1;
    }
 
    vector<Query> queries;
 
    loop(i, Q){
        ll a, b, k;
        cin >> a >> b >> k;
        queries.pb(Query(a, b, k));
    }
 
    vector<Query> ogQeuries = queries;
    sort(all(queries));
 
 
    vector<ll> diffs;
    vector<ll> diffdiffs;


    ll prevExp = 0;
    for(auto q : queries){
        //printf("Query %lld %lld %lld\n", q.node1, q.node2, q.k);
        ll diff = q.k - prevExp;
        prevExp = q.k;
 
 
        //printf("Pushing diff %lld\n", diff);
        diffs.pb(diff);
    }
 
    sort(all(diffs));
    diffMatrix[0] = Matrix(1);
    ll prevDiff = 0;
 
    for(auto diff : diffs){
        
        ll diffdiff = diff - prevDiff;
        prevDiff = diff;

        diffdiffs.pb(diffdiff);
 
    }

    sort(all(diffdiffs));
    diffdiffMatrix[0] = Matrix(1);
    ll prevDiffDiff = 0;
    Matrix roll = Matrix(1);

    for(auto diffdiff : diffdiffs){
        
        ll diffdiffdiff = diffdiff - prevDiffDiff;
        prevDiffDiff = diffdiff;

 
        if(diffdiffdiff == 0)continue;
        //printf("calculating diffdiff %lld ---> diffdiffdiff %lld\n", diffdiff, diffdiffdiff);
        roll = roll * fastPow(base, diffdiffdiff);
        //printMatrix(roll);
        diffdiffMatrix[diffdiff] = roll;
    }


    roll = Matrix(1);
    prevDiff = 0;
    for(auto diff : diffs){
        
        ll diffdiff = diff - prevDiff;
        prevDiff = diff;

 
        if(diffdiff == 0) continue;
        //printf("calculating diff %lld ---> diffdiff %lld\n", diff, diffdiff);
        roll = roll * diffdiffMatrix[diffdiff];
        //printMatrix(roll);
        diffMatrix[diff] = roll;
    }
 
    roll = Matrix(1);
    prevExp = 0;
 
    for(auto q : queries){
 
        ll diff = q.k - prevExp;
        prevExp = q.k;
 
        roll = roll * diffMatrix[diff];
        ll ans = roll.a[q.node1-1][q.node2-1];
 
        answers[q] = ans;
    } 
    
    for(auto q : ogQeuries){
        //printf("query %lld %lld %lld\n", q.node1, q.node2, q.k);
        cout << answers[q] << endl;
    }
 
}
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}