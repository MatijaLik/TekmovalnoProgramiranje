/**
 * Author: MatijaL
 * Time: 2021-09-28 16:35:02
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
    int n;
    cin >> n;
    priority_queue<pll> q;
    loop(i, n){
        int e;
        cin >> e;
        if(e!=0)q.push(mp(e, i+1));
    }
    vector<pll> ans;
    while(q.size() > 1){
        pll e = q.top();
        q.pop();
        pll f = q.top();
        q.pop();

        ans.pb(mp(e.sc, f.sc));
        if(e.fs > 1) q.push(mp(e.fs-1, e.sc));
        if(f.fs > 1) q.push(mp(f.fs-1, f.sc));

    }
    cout << ans.size() << endl;
    for(auto e : ans){
        cout << e.fs <<  " "  << e.sc << endl;
       }
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
