/**
 * Author: MatijaL
 * Time: 2020-11-15 15:35:01
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
    ll N, W;
    cin >> N >> W;
    priority_queue<pll> q;
    ll bot = W/2 + W%2;
    ll top = W;
    FOR(i,1, N){
        ll w;
        cin >> w;
        q.push(mp(w, i));
    }

    ll sum = 0;
    vector<int> ans;
    while(!q.empty()){
        pll p = q.top();
        ll w = p.fs;
        ll id = p.sc;
        q.pop();

        if(sum + w <= W){
            ans.pb(id);
            sum += w;
        }

        if(bot <= sum and sum <= top){
            cout << ans.size() << endl;
            for(auto e : ans) cout << e << " ";
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
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
