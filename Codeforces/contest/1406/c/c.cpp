/**
 * Author: MatijaL
 * Time: 2020-09-12 15:45:01
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
#define limit 100300
vector<int> sosedi[limit];
int sz[limit];
int cost[limit];
int n;
void dfs(int node, int prev){
    int cnt = 1;
    for(auto sosed : sosedi[node]){
        if(sosed == prev) continue;
        dfs(sosed, node);
        cnt += sz[sosed];
        cost[node] = max(cost[node], sz[sosed]);
    }
    sz[node] = cnt;
    cost[node] = max(cost[node], n - sz[node]);
}
void solve(){
    
    cin >> n;
    loop(i, n+10){
        sosedi[i].clear();
        sz[i] = 0;
        cost[i] = 0;
    }
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    dfs(1, 0);
    /*
    FOR(i, 1, n)
        printf("Node %lld, size %lld cost %lld\n", i, sz[i], cost[i]);
        */

    vector<int> same;
    int lowest = inf;
    FOR(i, 1, n){
        if(cost[i] == lowest){
            same.pb(i);
        }
        if(cost[i] < lowest){
            lowest = cost[i];
            same.clear();
            same.pb(i);
        }
        
    }
    if(same.size() == 1){
        printf("%d %d\n", 1, sosedi[1][0]);
        printf("%d %d\n", 1, sosedi[1][0]);
    }else{
        int a = same[0];
        int b = same[1];
        int child = sosedi[a][0];
        if(child == b) child = sosedi[a][1];
        printf("%d %d\n", a, child);
        printf("%d %d\n", b, child);
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
