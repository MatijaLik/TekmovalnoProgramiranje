/**
 * Author: MatijaL
 * Time: 2021-01-02 20:08:37
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
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

void solve(){
    ll cnt[62];
    memset(cnt, 0, sizeof cnt);
    int N;
    cin >> N;
    vector<ll> v(N);
    loop(i, N) cin >> v[i];
    loop(bit, 62){
        for(auto e : v){
            if(e & (1LL << bit)) cnt[bit]++;
        }
    }
    ll ans = 0;
    for(auto e : v){
        ll f = 0;
        ll s = 0;
        loop(bit, 62){
            ll base = (1LL << bit);
            base %= mod;
            if(e & (1LL << bit)) s += N*base;
            else s += cnt[bit]*base;
            s %= mod;

            if(e& (1LL << bit)) f += cnt[bit]*base;
            f %= mod;
        }
        ll prod = f*s;
        prod %= mod;
        ans += prod;
        ans %= mod;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
