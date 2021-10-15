/**
 * Author: MatijaL
 * Time: 2021-09-28 16:35:02
**/
#pragma optimize("O3")
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
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];

    multiset<int> s;

    s.insert(v[0]);
    int ans = 0;
    FOR(i, 1, n-1){
        int e = v[i];
        int vec = distance(s.upper_bound(e), s.end());
        int manj = s.size() - distance(s.lower_bound(e),s.end());
        if(vec > manj){
               ans += manj;  
        }
        else {
             ans += vec;
        }
        s.insert(v[i]);
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
