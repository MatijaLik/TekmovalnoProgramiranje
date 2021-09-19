/**
 * Author: MatijaL
 * Time: 2021-05-22 09:11:21
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

#define limit 100500

#define DEBUG 0

int lowlink[limit];
int dfsnum[limit];
int component[limit];
vector<int> groups[limit];

int curComp = 1;
int cas = 1;

//1-indexed array
vector<int> a(limit);
stack<int> s;

void dfs(int node){
    lowlink[node]=cas;
    dfsnum[node]=cas++;

    s.push(node);

    //printf("dfs %d\n", node);

    if(dfsnum[a[node]] == 0){
        dfs(a[node]);
        lowlink[node] = min(lowlink[node], lowlink[a[node]]);
    }else if(dfsnum[a[node]] != -1){
        lowlink[node] = min(lowlink[node], dfsnum[a[node]]);
    }

    if(lowlink[node] == dfsnum[node]){
        int lastOne = -1;
        while(1){
            lastOne = s.top();
            s.pop();
            dfsnum[lastOne] = -1;
            component[lastOne] = curComp;
            groups[curComp].pb(lastOne);
            if(lastOne == node) break;
        }
        curComp++;
    }
}




vector<int> parents[limit];
int child[limit];

void solve(){
    int N, K;
    cin >> N >> K;
    loop(i, N) cin >> a[i+1];

    //dfs
    FOR(u, 1, N){
        if(dfsnum[u] == 0) dfs(u);
    }

    if(DEBUG){
        FOR(i, 1, curComp){
            print(groups[i]);
        }
    }
    
    //naredi novi graf
    int n = curComp-1;
    int in[limit];
    memset(in, 0, sizeof in);
    FOR(i, 1, N){
        //povezava u->v
        int u = component[i];
        int v = component[a[i]];

        if(u==v) continue;
        child[u] = v;
        parents[v].pb(u);

        in[v]++;
    }

    //naredi rikverc topological sort
    vector<int> sorci; //toti ki jih moramo obvezno porabiti
    queue<int> q;
    FOR(i, 1, n) if(in[i] == 0) {
        sorci.pb(i);
        q.push(i);
    }

    vector<int> topoSort;

    //topo sort
    while(!q.empty()){
        int e = q.front();
        q.pop();
        topoSort.pb(e);

        in[child[e]]--;
        if(in[child[e]] == 0) q.push(child[e]);
    }

    if(DEBUG) print(topoSort);
    reverse(all(topoSort));


    vector<int> finalAns;

    assert(sorci.size() <= K);

    
    loop(i, K-sorci.size()) finalAns.pb(topoSort[i]);
    for(auto e : sorci) finalAns.pb(e);
    

    //prevedi koncni odgovor
    for(auto e : finalAns) printf("%d ", groups[e][0]);
    printf("\n");
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    solve();   
}
