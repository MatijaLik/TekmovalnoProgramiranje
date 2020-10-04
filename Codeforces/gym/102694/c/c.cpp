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
vector<int> sosedi[limit];
int parent[limit][21];
int depth[limit];

void dfs(int node, int prev, int dpt){
    depth[node] = dpt; 
    parent[node][0] = prev;
    for(auto sosed : sosedi[node]){
        if(sosed == prev) continue;
        dfs(sosed, node, dpt+1);
    }
}
int binlift(int node, ll exp){
    int i = 0;
    int cn = node;
    while(exp != 0){
        if(exp%2) cn = parent[cn][i]; 
        exp /= 2;
        i++;
    }
    return cn;
}
int LCA(int a, int b){
   if(depth[a] > depth[b]) a = binlift(a, depth[b] - depth[a]);
   if(depth[b] > depth[a]) b = binlift(b, depth[a] - depth[b]);
   if(a == b) return a;
   for(int exp = 20; exp >= 0; exp--){
       int liftA = binlift(a, 1 << exp);
       int liftB = binlift(b, 1 << exp);
       if(liftA != liftB){
           a = liftA;
           b = liftB;
       }
   }
   return parent[a][0];
}
ll dist(int u, int v){
    return depth[u] + depth[v] - 2*depth[LCA(u, v)];
}
ll query(int a, int b, int c){
    if(a == b) return a;
    ll len = dist(a, b);
    if(c >= len) return b;
    ll m = LCA(a, b);
    if(c <= dist(a, m)) return binlift(a, c);
    return binlift(b, len - c);
}
void solve(){
    int n, q;
    cin >> n;
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    dfs(1, 1, 0);
    //precompute
    FOR(exp, 1, 20){
        FOR(node, 1, n){
            parent[node][exp] = parent[parent[node][exp-1]][exp-1];
        }
    }

    cin >> q;
    loop(i,q){
        int a, b, c;
        cin >> a >> b >> c;
        printf("%lld\n", query(a, b, c));
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
