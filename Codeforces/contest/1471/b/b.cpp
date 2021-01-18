/**
 * Author: MatijaL
 * Time: 2021-01-06 18:18:07
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
    ll ans = 0;
    int n, x;
    cin >> n >> x;
    vector<pll> v;
    loop(i, n){
        ll t;
        cin >> t;
        v.pb(mp(t, 1));
        ans += t;
    }
    for(int i  = 0; i < v.size(); i++){
        pll e = v[i];
        ll num = e.fs;
        ll mul = e.sc;

        if(num%x) break;
        v.pb(mp(num/x, mul*x));
        ans += num*mul;
    }
    cout << ans << endl;
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
