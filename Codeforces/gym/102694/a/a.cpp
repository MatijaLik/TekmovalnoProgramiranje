/**
 * Author: MatijaL
 * Time: 2020-08-19 19:48:26
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
#define inf 1000000000
#define mod 1000000007
#define limit 300100
int n;
vector<int> sosed[limit];
int maxD = 0;
int maxNode = 1;
ll ans[limit];
ll dpt[limit];

void dfs(int node, int prev, int depth){
    if(depth > maxD){
        maxD = depth;
        maxNode = node;
    }
    dpt[node] = depth;
    for(auto sosed : sosed[node]){
       if(sosed == prev) continue;
       dfs(sosed, node, depth+1);
    }
}
void dfs2(int node, int prev, int depth){
    dpt[node] = max(depth, dpt[node]);
    for(auto sosed : sosed[node]){
       if(sosed == prev) continue;
       dfs(sosed, node, depth+1);
    }
}

void solve(){
   cin >> n;
   loop(i, n-1){
       int a, b;
       cin >> a >> b;
       sosed[a].pb(b);
       sosed[b].pb(a);
   }
   dfs(1, 0, 0);
   maxD = 0;
   dfs(maxNode, 0, 0);
   dfs2(maxNode, 0, 0);
   FOR(i, 1, N) cout << dpt[i]+1 << endl;
  
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
