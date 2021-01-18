/**
 * Author: MatijaL
 * Time: 2020-09-23 18:43:46
**/
 
#include <stations.h>
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
const int limit = 2000;
vector<int> sosedi[limit];
int in[limit];
int out[limit];
int depth[limit];
int cas = 1;
 
 
//cas se incrementa za vsako povezavo v vsako smer!!
void dfs(int node, int prev, int dpt){
    in[node] = cas;
    depth[node] = dpt;
    for(auto sosed : sosedi[node]){
        if(sosed != prev){
            cas++;
            dfs(sosed, node, dpt+1);
        }
    }
    
    cas++;
    out[node] = cas;
}
 
vector<int> label(int n, int k, vector<int> u, vector<int> v){
    //reset
    cas = 1;
    loop(i, limit) sosedi[i].clear();
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    memset(depth, 0, sizeof depth);
 
    loop(i, n-1){
        int a = u[i];
        int b = v[i];
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    dfs(0, 0, 0);
    map<int, int> fi;
    vector<int> indeces;
 
    loop(i, n){
        if(depth[i] % 2 == 0){
            indeces.pb(in[i]);
            fi[in[i]] = i;
        }else{
            indeces.pb(out[i]);
            fi[out[i]] = i;
        }
    }
    //compression
    sort(all(indeces));
    vector<int> ans(n);
    
    int i = 0;
    for(auto index : indeces){
        int node = fi[index];
        ans[node] = i;
        i++;
    }
    return ans;
}
int find_next_station(int cur, int goal, vector<int> adjacent){
 
    if(cur == goal) return cur;
    for(auto e : adjacent) if(e == goal) return e;
    
    int mn = inf;
    int mx = -1;
    for(auto e : adjacent){
        mn = min(mn, e);
        mx = max(mx, e);
    }
 
    //ugotovi depth
    int depth;
    if(adjacent[0] > cur) depth = 0;
    else depth = 1;
    sort(all(adjacent));
    if(depth == 0){
        if(cur == 0){
            return *upper_bound(all(adjacent), goal); 
        }
        //cur je in poddrevesa
        //parent je mx
        int parent = mx;
        if(adjacent.size() == 1) return parent;
 
        reverse(all(adjacent));
        int maxChild = adjacent[1];
 
        reverse(all(adjacent));
        if(goal < cur or goal > maxChild) return parent;
        else return *upper_bound(all(adjacent), goal);  
    }
    else{
        //cur je out poddrevesa 
        int parent = mn;
        if(adjacent.size() == 1) return parent;
 
        int minChild = adjacent[1];
        if(goal < parent or goal > cur) return parent;
        return *(upper_bound(all(adjacent), goal) - 1);
    }
 
}
