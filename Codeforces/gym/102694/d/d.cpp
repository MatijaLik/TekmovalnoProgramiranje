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
#define inf 1000002000
#define mod 1000000007
#define limit 300100
vector<pll> sosedi[limit];
pll parent[limit][21];
int depth[limit];
 
void dfs(int node, int prev, int dpt){
    depth[node] = dpt; 
    for(auto sosed : sosedi[node]){
        ll next = sosed.fs;
        ll weight = sosed.sc;
        if(next == prev) continue;
        parent[next][0] = mp(node, weight);
        dfs(next, node, dpt+1);
    }
}
pll binlift(int node, ll exp){
    int i = 0;
    int cn = node;
    ll bottleneck = inf;
    while(exp != 0){
        if(exp%2){
            bottleneck = min(bottleneck, parent[cn][i].sc);
            cn = parent[cn][i].fs;
        }
        exp /= 2;
        i++;
    }
    return mp(cn, bottleneck);
}
int LCA(int a, int b){
   ll bottleneck = inf;
   if(depth[a] > depth[b]){
        bottleneck = binlift(a, depth[a] - depth[b]).sc;
        a = binlift(a, depth[a] - depth[b]).fs;
   } 
   if(depth[b] > depth[a]){
        bottleneck = binlift(b, depth[b] - depth[a]).sc;
        b = binlift(b, depth[b] - depth[a]).fs;
   }
   if(a == b) return bottleneck;
   for(int exp = 20; exp >= 0; exp--){
       int liftA = binlift(a, 1 << exp).fs;
       int liftB = binlift(b, 1 << exp).fs;
       if(liftA != liftB){
           bottleneck = min(bottleneck, binlift(a, 1 << exp).sc);
           bottleneck = min(bottleneck, binlift(b, 1 << exp).sc);
           a = liftA;
           b = liftB;
       }
   }
   /*
    *   LCA
    *  /  |
    *  A  B
    */
   bottleneck = min(bottleneck, binlift(a, 1).sc);
   bottleneck = min(bottleneck, binlift(b, 1).sc);
   return bottleneck;
}

void solve(){
    int n, m, q;
    cin >> n >> m;
    loop(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        sosedi[a].pb(mp(b, c));
        sosedi[b].pb(mp(a, c));
    }
    dfs(1, 1, 0);
    //precompute
    parent[1][0] = mp(1, inf);
    FOR(exp, 1, 20){
        FOR(node, 1, n){
            pll hop1 = parent[node][exp-1];
            pll hop2 = parent[hop1.fs][exp-1];
            parent[node][exp] = mp(hop2.fs, min(hop1.sc, hop2.sc));
        }
    }
 
    cin >> q;
    loop(i,q){
        ll a, b;
        cin >> a >> b;
        printf("%lld\n", LCA(a, b));
    }
    return;
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
