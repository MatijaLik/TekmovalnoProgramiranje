/**
 * Author: MatijaL
 * Time: 2020-09-02 15:06:54
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
#define limit 200100
int segtree[4*limit];
int in[limit];
int out[limit];
int depth[limit];
int N, Q;
int cas = 0;
vector<int> sosedi[limit];
void dfs(int node, int prev, int dpt){
    in[node] = ++cas;
    depth[node] = dpt; 
    for(auto sosed: sosedi[node]){
        if(sosed == prev) continue;
        dfs(sosed, node, dpt+1);
    }
    out[node] = cas;
}
int left(int i){return 2*i;}
int right(int i){return (2*i)+1;}
int mid(int l, int r){return (l+r)/2;}
void segi(int i, int l, int r, int ql, int qr, int val){
    //zunaj
    if(qr < l or r < ql) return;
    if(ql <= l and r <= qr){
        segtree[i] = val;
        return;
    }
    if(l == r) return;
    int m = mid(l, r);
    segi(left(i), l, m, ql, qr, val);
    segi(right(i), m+1, r, ql, qr, val);
}
int segq(int i, int l, int r, int id, int goal){
    //maksimum na poti do id
    if(id < l or r < id) return -1;
    int cur = segtree[i];
    if(l == r or cur == goal) return cur;
    int m = mid(l, r);
    int val1 = segq(left(i), l, m, id, goal);
    int val2 = segq(right(i), m+1, r, id, goal);
    return max(cur, max(val1, val2));

}
int query(int id){
    int r;
    scanf("%d", &r);
    vector<pair<int, int>> nodes;
    loop(i, r){
        int node;
        scanf("%d", &node);
        nodes.pb(mp(depth[node], node));
    }
    sort(all(nodes));

    int cnt = 0;
    for(auto p : nodes){
        int node = p.sc;
        if(r == 1) return out[node] - in[node] + 1;
        int cover;
        cover = segq(1, 1, N, in[node], id);
        if(cover == id) continue;
        

        int toAdd = out[node] - in[node] + 1;
        //printf("node %lld (depth %d) adding %lld\n", node, depth[node], toAdd); 
        //dodaj in pristej
        cnt += toAdd;
        segi(1, 1, N, in[node], out[node], id);
    }
    return cnt;
}
void solve(){
    scanf("%d %d", &N, &Q);
    loop(i, N-1){
        int a, b;
        scanf("%d %d", &a, &b);
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    dfs(1, 1, 0);
    loop(i, Q) printf("%d\n", query(i+1));
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
