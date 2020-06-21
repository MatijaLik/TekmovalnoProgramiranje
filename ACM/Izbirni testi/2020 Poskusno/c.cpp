#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl


vector<int> paketi;


int S, K, P;

int main(){
    cin >> S >> P >> K;
    loop(i, P){
        int mask = 0;
        loop(j, K){
            int a;
            cin >> a;
            mask |= (1 << (a-1));
        }
        paketi.pb(mask);
    }

    ll res = 0;

    //sprobaj vse kombinacije
    for(int i = 0; i < (1 << P); i++){
        int sum = 0;
        
        //za vsak paketek daj AND
        loop(p, P){
            if(i & (1 << p)){
                //printf("using package %d\n", p);
                sum = sum | paketi[p];
            }
        }
        //printf("i %d, sum = %d\n", i, sum);
        if(sum == (1 << S) - 1)res++;

    }
    cout << res << endl;
}