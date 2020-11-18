/**
 * Author: MatijaL
 * Time: 2020-11-06 13:51:26
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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n) cin >> a[i];

    
    int r = 1;
    queue<int> v[2];
    vector<pll> ans;
    FOR(i, 0, n-1){
        int e = a[i];
        if(e == 0) continue;
        if(e >= 2) v[e-2].push(r);
        
        
        if(e == 1){
            if(!v[0].empty()){
                int id = v[0].front();
                v[0].pop();
                ans.pb(mp(id, i+1));
                r++;
            }
            else if(!v[1].empty()){
                int id = v[1].front();
                v[1].pop();
                ans.pb(mp(id, i+1));
                ans.pb(mp(r, i+1));
                r++;
            }else{
                ans.pb(mp(r, i+1));
                r++;
            }
        }
        if(e == 2){
            if(!v[1].empty()){
                int id = v[1].front();
                v[1].pop();
                ans.pb(mp(id, i+1));
                ans.pb(mp(r, i+1));
                r++;
            }else{
                ans.pb(mp(r, i+1));
                r++;
            }
        }
        if(e == 3){
            if(v[1].size()>1){
                int id = v[1].front();
                v[1].pop();
                ans.pb(mp(id, i+1));
                ans.pb(mp(r, i+1));
                r++;
            }else{
                ans.pb(mp(r, i+1));
                r++;
            }
        }
    }
    if(!v[0].empty() or !v[1].empty()) cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        for(auto e : ans) cout << e.fs << " " << e.sc << endl;
    }
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
