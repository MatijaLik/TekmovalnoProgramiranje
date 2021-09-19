/**
 * Author: MatijaL
 * Time: 2021-08-20 21:50:00
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
const bool DEBUG = 0;
void solve(){
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> vec;
    loop(i, n){
        int c, f, v;
        cin >> c >> f >> v;
        v = -v;
        vec.pb(mp(f, mp(c, v)));
    }
    int m;
    cin >> m;
    loop(i, m){
        int c, f, v;
        cin >> c >> f >> v;
        c = -c;
        vec.pb(mp(f, mp(c, v)));
    }
    sort(all(vec));
    reverse(all(vec));

    vector<ll> dp(50*n + 1, LONG_LONG_MIN);
    dp[0] = 0;
    loop(i, n+m){
        vector<ll> next(50*n +1, LONG_LONG_MIN);
        copy(all(dp), next.begin());
        int c, v;
        c = vec[i].sc.fs;
        v = vec[i].sc.sc;
        FOR(j, 0, 50*n){
            if(0 <= j + c and dp[j] != LONG_LONG_MIN) next[j+c] = max(next[j+c], dp[j] + v);
        }
        copy(all(next), dp.begin());
    }
    ll ans = 0;
    for(auto e : dp) ans = max(ans, e);
    cout << ans << endl;
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t =1;
    while(t--) solve();   
}
