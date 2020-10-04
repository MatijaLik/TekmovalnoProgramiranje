/**
 * Author: MatijaL
 * Time: 2020-09-21 15:05:48
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
const int limit = 1010;
int N;
int component[limit];
int rib[limit];

int parent1[limit];
int rank1[limit];

int find1(int node){
    if(parent1[node] != node) return find1(parent1[node]);
    return node;
}
void un1(int u, int v){
    if(find1(u) == find1(v)) return;
    if(rank1[u] < rank1[v]) swap(u, v);
    if(rank1[u] == rank1[v]) rank1[u]++;
    parent1[v] = u;
}
vector<int> comps[limit];
void resetDsu(){
    loop(i, limit){
        parent1[i] = i;
        rank1[i] = 0;
    }
}
void build(vector<vector<int>> v){
    for(auto e  : v){
        for(auto h : e){
            cout << h << " ";

        }
        cout << endl;
    }
}

int construct(vector<vector<int>> p){
    N = p.size();
    resetDsu();
    
    //check for 3
    loop(i, N) loop(j, N) if(p[i][j] == 3) return 0;

    //divide into components
    set<int> visited;
    map<int, int> compId;
    int id = 0;
    loop(i, N){
        loop(j, N){
            //gledamo i x i-1
            if(p[i][j] > 0){
                un1(i, j);
            }
        }
    }
    //assign component id
    loop(i, N){
        int loc = find1(i);
        if(visited.count(loc) == 0){
            visited.insert(loc);
            compId[loc] = id++;
        }
        int pos = compId[loc];
        comps[pos].pb(i); 
        component[i] = pos;
    }
    //check collisions
    loop(i, N){
        loop(j, N){
            if(i == j) continue;
            if(component[i] != component[j] and p[i][j] > 0) return 0;
            if(component[i] == component[j] and p[i][j] == 0) return 0;
        }
    }

    resetDsu(); 
    vector<vector<int>> b(N, vector<int>(N, 0));
    //Handle each component
    loop(c, id){
        vector<int> nodes = comps[c];

        //prepare the ribs
        for(auto i : nodes) for(auto j : nodes){
            if(i == j) continue;
            if(p[i][j] == 1) un1(i, j);
        }

        //prepare edges
        vector<int> roots;
        set<int> rootSet;
        for(auto i : nodes){
            int par = find1(i);
            if(rootSet.count(par) == 0){
                rootSet.insert(par);
                roots.pb(par);
            }
            if(par == i) continue;
            b[par][i] = 1;
            b[i][par] = 1;
        }

        //make a loop out of the roots
        if(roots.size() == 2) return 0;
        if(roots.size() > 2){
            loop(i, roots.size()){
                int u = roots[i];
                int v = roots[(i+1)%roots.size()];
                b[u][v] = 1;
                b[v][u] = 1;
            }
        }
        
        //check for collisions
        for(auto i : nodes) for(auto j : nodes){
            if(i == j) continue;
            if(find1(i) != find1(j) and p[i][j] == 1) return 0;
            if(find1(i) == find1(j) and p[i][j] == 2) return 0; 
        }

    
    }
    build(b);
    return 1;
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(n));
    loop(i, n)loop(j, n) cin >> p[i][j];
    int ans = construct(p);
    if(ans == 0) cout << "BAD" << endl;
}
