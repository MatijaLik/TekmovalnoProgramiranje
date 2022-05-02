#include <iostream>
#include <vector>
#include <cstring>
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
    unsigned int a[200][200];
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
                    res.a[i][k] += ((long long)a[i][j] * (long long)other.a[j][k])%mod;
                    res.a[i][k] %= mod;
                }
            }
        }
        return res;
    }

    vector<ll> operator * (vector<ll> v){
        vector<ll> res(200);
        loop(i, 200){
            loop(j, 200){
                res[i] += v[j] * a[j][i];
                res[i] %= mod;
            }
        }
        return res;
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
    cin >> N >> M >> Q;
 
    //sestavimo base
    Matrix base = Matrix();
    
    
    loop(i, M){
        ll a, b;
        cin >> a >> b;
        base.a[--a][--b] = 1;
    }
    
    //precompute
    Matrix mexp[32];
    mexp[0] = Matrix(1);
    FOR(i, 1, 31){
        mexp[i] = base;
        //printf("Matrix %lld\n", i);
        //1printMatrix(base);
        base = base * base;
    }


    loop(i, Q){
        ll a, b, k;
        cin >> a >> b >> k;

        vector<ll> v(200);
        v[a-1] = 1;

        int it = 1;
        while(k){
            if(k%2){
                v = mexp[it]*v;
            }
            it++;
            k/=2;
        }

        cout << v[b-1] << endl;
    }
 
 
}
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}