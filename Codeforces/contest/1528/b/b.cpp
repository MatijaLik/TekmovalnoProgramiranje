/**
 * Author: MatijaL
 * Time: 2021-06-20 17:51:04
**/

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
#define inf 1000000005
#define mod 998244353
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

#define limit 1000500

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }

    ll f[limit];
    ll g[limit];
    memset(g, 0, sizeof g);
    
    f[1] = 1;
    f[2] = 3;
    loop(i, limit) g[i] = 1;
    FOR(i, 1, limit){
        int j = 2*i;
        for(; j < limit; j+=i) {
            g[j] += 1;
            g[j] %= mod;
        }

        if(i >= 3){
            f[i] = (g[i] + (2*f[i-1]-g[i-1]));
            f[i] = (f[i] + mod) % mod;
        }

        //printf("i %lld| g %lld| f %lld\n", i, g[i], f[i]);
    }
    cout << f[n];
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
