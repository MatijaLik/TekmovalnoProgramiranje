/**
 * Author: MatijaL
 * Time: 2021-06-20 17:51:04
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

#define limit 200100

ll sum = 0;
vector<int> sosedi[limit];
pll v[limit];
ll num[limit];


set<pll> memoS;
map<pll, ll> memo;

ll dfs(int node, int prev, ll val){

    if(memoS.count(mp(node, val))) return memo[mp(node, val)];
    memoS.insert(mp(node, val));

    ll sum1 = 0;
    ll sum2 = 0;
    if(val != -1) sum1 += abs(v[node].fs - val);
    if(val != -1) sum2 += abs(v[node].sc - val);
    for(auto e : sosedi[node]){
        if(e == prev) continue;
        sum1 += dfs(e, node, v[node].fs);
        sum2 += dfs(e, node, v[node].sc);
    }

    return memo[mp(node, val)] = max(sum1, sum2);
}


void solve(){
    memoS.clear();
    int n;
    cin >> n;
    loop(i, n+1) sosedi[i].clear();  
    sum = 0;
    loop(i, n){
        ll l, r;
        cin >> l >> r;
        v[i+1] = mp(l, r);
    }

    loop(i, n-1){
        int u, v;
        cin >> u >> v;
        sosedi[u].pb(v);
        sosedi[v].pb(u);
    }
    
    cout << dfs(1, 1, -1) << endl;
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
