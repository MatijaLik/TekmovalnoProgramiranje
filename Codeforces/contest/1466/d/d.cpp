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
vector<ll> inc;
vector<int> sos[100100];
ll val[100100];
void dfs(int node, int prev){
    int cnt = 0;
    for(auto e : sos[node]){
        if(e == prev) continue;
        cnt++;
        dfs(e, node);
    }
    if(node == 0) cnt--;
    loop(i, cnt) inc.pb(val[node]);
}
void solve(){
    int n;
    inc.clear();
    cin >> n;
    loop(i, n) sos[i].clear();
    loop(i, n) cin >> val[i];
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        sos[a].pb(b);
        sos[b].pb(a);
    }
    dfs(0, -1);
    ll sum = 0;
    loop(i, n) sum += val[i];
    sort(all(inc));
    reverse(all(inc));
    cout << sum << " ";
    loop(i, n-2){
        sum += inc[i];
        cout << sum << " ";
    }
    cout << endl;
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
