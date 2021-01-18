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
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<ll> c(m);
    loop(i, n) cin >> k[i];
    loop(i, m) cin >> c[i];

    sort(all(k));
    ll ans = 0;
    int p = 0;
    reverse(all(k));
    for(auto e : k){
        if(p < e){
            ans += c[p];
            p++;
        }else{
            ans += c[e-1];
        }
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
