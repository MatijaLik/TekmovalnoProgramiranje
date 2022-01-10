#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define limit 200500

int par[limit];
int depth[limit];
vector<int> sosedi[limit];
int color[limit];


void dfs(int node, int prev){
    if(node!=1) depth[node] = depth[prev] +1;
    par[node] = prev;
    for(auto e : sosedi[node]) if(e != prev) dfs(e, node);
}

void dfs1(int node, int k){
    color[node] = 1;
    if(k!=0) for(auto e : sosedi[node]) if(e != par[node]) dfs1(e, k-1);
}

int dfs2(int node, int k){
    int ans = 0;
    if(color[node]) ans++;
    if(k!=0) for(auto e : sosedi[node]) if(e!=par[node]) ans += dfs2(e, k-1);
    return ans;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    for(int i=0;i<N;i++){
        cin >> color[i+1];
    }

    dfs(1,1);

    int Q;
    cin >> Q;
    for(int q=0;q<Q;q++){
        int t, x, k;
        cin >> t >> x >> k;
        if(t==1) dfs1(x, k);
        else cout << dfs2(x, k) << endl;
    }
}
