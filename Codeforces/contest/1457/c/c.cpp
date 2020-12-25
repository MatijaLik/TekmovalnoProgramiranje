/**
 * Author: MatijaL
 * Time: 2020-11-29 14:08:46
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
    int n, p, k;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    bool v[n];
    loop(i, n) v[i] = s[i] == '1';

    int dp[n];
    loop(i, n) dp[i] = inf;
    FOR(pos, n-k, n-1) dp[pos] = v[pos] ? 0 : 1;
    for(int pos = n-k-1; pos >= 0; pos--){
        dp[pos] = v[pos] ? dp[pos+k] : dp[pos+k] + 1;
    }

    ll x, y;
    cin >> x >> y;
    ll best = inf*1LL*inf;
    loop(i, n){
        if(i < p-1) continue;
        best = min(best, y*(i-p+1) + dp[i]*x);
    }
    cout << best << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
