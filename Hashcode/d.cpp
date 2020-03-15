#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pli pair<long long, int>
#define vi vector <int>
#define mii map<int, int>
#define si set<int>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

bitset<310> B[310];     
int D [310][310];
int N, K;
int sum;

struct query
{
    int a;
    int b;
    int x;

    query(int n1, int n2, int n3) : a(n1), b(n2), x(n3)
    {
    }

    bool operator<(const struct query& other) const
    {
        //Your priority logic goes here
        return x > other.x;
    }
};


void resetArr(){
    loop(i, N){
        B[i].reset();
    }
}

priority_queue<query> q;

void visit(int a, int b, int x){
    int cur = D[a][b];
    if(x >= cur) return;
    D[a][b] = x;
    D[b][a] = x;
    /*
    debug(a);
    debug(b);
    debug(x);
    debug("####");
    */
    sum -= cur - x;
    cur = x;
    FOR(i,1, N+1){
        if(i == a || i == b) continue;
        int ca = D[a][i];
        int cb = D[b][i];
        //cout << "inspecting " << i << endl;
        if(ca + cur < cb){
            q.push(query(b, i, ca+cur));
            //visit(b, i, ca+cur);
        }
        if(cb + cur < ca){
            q.push(query(a, i, cb+cur));
            //visit(a, i, cb+cur);
        }
    }
    
    if(!q.empty()){
        query p = q.top();
        q.pop();
        visit(p.a, p.b, p.x);
    }
}

int main(){
    cin >> N;
    loop(i, N) loop(j, N){
        int t;
        cin >> t;
        D[i+1][j+1] = t;
        if(i < j) sum += t;
    }
    //cout << " initial sumn " << sum << endl;
    cin >> K;
    loop(i, K){
        int a, b, x;
        cin >> a >> b>> x;
        visit(a, b, x);
        //resetArr();
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
