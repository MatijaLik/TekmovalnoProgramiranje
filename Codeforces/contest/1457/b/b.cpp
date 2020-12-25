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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    ll best = inf;

    FOR(color, 1, 100){
        ll cnt = 0;
        loop(i, n){
            if(v[i] != color){
                i += k-1;
                cnt++;    
            }
        }
        best = min(best, cnt);
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
