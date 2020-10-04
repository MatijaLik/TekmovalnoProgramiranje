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
#define limit 100010
int visited[limit];
int target[limit];
vector<int> sosedi[limit];
int cnt = 0;


vector<int> targets;
set<int> sosediSet[limit];


void dfs1(int node){
    cnt++;
    visited[node] = 1;
    for(auto sosed : sosedi[node]){
        if(!visited[sosed] and target[sosed]) dfs1(sosed);
    }
}
void dfs2(int node){
    cnt++;
    visited[node] = 1;
    for(auto v : targets){
        if(!visited[v] and sosediSet[node].count(v)) dfs2(v);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    loop(i, m){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
        sosediSet[a].insert(b);
        sosediSet[b].insert(a);
    }
    int Q;
    cin >> Q;



    loop(q, Q){
        int r;
        cin >> r;
        int node;   

        cnt = 0;
        targets.clear();

        loop(i, r){
            cin >> node;
            target[node] = 1;
            visited[node] = 0;
            targets.pb(node);
        }
        //loop(i, n) printf("%lld ", target[i]);
        //printf("\n");
        const int treshold = 10000;
        if(r >= treshold) dfs1(node);
        else dfs2(node);
        
        for(auto v : targets){target[node] = 0;visited[node] = 0;}
        if(cnt >= r) cout << "DA" << endl;
        else cout << "NE" << endl;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
