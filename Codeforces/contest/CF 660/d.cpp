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

int input[limit];
int output[limit];

int dag1Next[limit];
vector<int> dag1Prev[limit];

ll value[limit];
ll rollingSum[limit];

vector<int> dag2Prev[limit];

stack<int> dfs2Todo;
vector<int> ansv;
ll ans = 0;

void dfs(int node){

    //printf("DFS %lld\n", node);


    ll total = 0;

    //dfs na vse prednike
    for(auto prev : dag1Prev[node]){
        dfs(prev);
        if(rollingSum[prev] > 0){
            total += rollingSum[prev];
            dag2Prev[node].pb(prev);//kvaliteta
        }
    }

    //printf("DFS %lld | best is %lld \n", node, bestNode);
    rollingSum[node] = total + value[node];
}

void dfs2(int node){
    //printf("DFS %lld\n", node);
    
    for(auto prev : dag2Prev[node]){
        dfs2(prev);
    }
        
    ansv.pb(node);
    ans += rollingSum[node];

    for(auto prev : dag1Prev[node]){
        
        if(not(isIn(dag2Prev[node], prev))){
            dfs2Todo.push(prev);
            //printf("pushing %lld\n", prev);
        }
    }
    //printf("DFS %lld END\n", node);
}   




void solve(){
    int N;
    cin >> N;

    FOR(i, 1, N){
        ll a;
        cin >> a;
        value[i] = a;
    }

    FOR(i, 1, N){
        ll b;
        cin >> b;
        if(b == -1) continue;


        //povezava i ---> b
        output[i]++;
        input[b]++;
        dag1Next[i] = b;
        dag1Prev[b].pb(i);


        //printf("adding linkk %lld => %lld\n", i, b);
    }

    
    //naredimo dfs za vsak list
    FOR(i, 1, N){
        if(output[i] == 0) dfs(i);
    }


    FOR(i, 1, N){
        //printf("Node %lld, prev is %lld\n", i, dag2Prev[i]);
    }

    FOR(i, 1, N){
        if(output[i] == 0) dfs2(i);
    }

    int i = 0;

    while(!dfs2Todo.empty() and i < 10){
        //cout << "Popping new ";
        //printf("ans is %lld\n", ans);
        
        int a = dfs2Todo.top();
        dfs2Todo.pop();
        dfs2(a);
    }

    cout << ans << endl;
    for(auto e : ansv) cout << e << " ";
    cout << endl;   

}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}