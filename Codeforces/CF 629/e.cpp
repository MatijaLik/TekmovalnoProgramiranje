#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl;

#define limit 300000

vector<ll> sosedi[limit];
ll parent[limit];
ll depth[limit];
ll visited[limit];

void DFS(ll node, ll d){
    depth[node] = d;
    visited[node] = 1;
    for(auto sosed : sosedi[node]){
        if(visited[sosed]==0){
            parent[sosed] = node;
            DFS(sosed, d+1);
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    loop(i, N-1){
        ll a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    DFS(1, 0);
    parent[1]= 1;
    
    ll parent[limit];
    loop()

    loop(q, M){
        ll curDepth = 0;
        ll k;
        cin >> k;
        set<ll> path;
        set<ll> cond;
        path.insert(1);
        bool gud = 1;
        loop(i, k){
            ll a;
            cin >> a;
            if(gud==0) continue;
            if(path.count(a)) continue;
            if(depth[a]<=curDepth){
                if(path.count(parent[a])){
                    cond.insert(a);
                }else{
                    //cout << a << endl;
                    cout << "NO" << endl;
                    gud = 0;
                }
            }else if(depth[a]>curDepth){
                ll cd = depth[a];
                ll node = a;
                while(cd > curDepth){
                    node = parent[node];
                    cd--;
                }
                if(path.count(parent[node])){
                    cond.clear();
                }else{
                    //cout << a << endl;
                    //cout << "druga" << endl;
                    cout << "NO" << endl;
                    gud = 0;

                }
                cd = depth[a];
                node = a;
                while(cd > curDepth){
                    node = parent[node];
                    path.insert(node);
                    //cout << "inserted " << node << endl; 
                    cd--;
                }
                cond.insert(a);
                curDepth = depth[a];
            }
        }
        if(gud)cout << "YES" << endl;
    }

}