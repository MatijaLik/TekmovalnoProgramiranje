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
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 1000020


ll N, M;
map<pll, bool> ans;
map<pll, bool> ancestry;
vector<ll> queriesByPackage[limit];
//set<pll> queriesSet;
vector<ll> queriesByBoss[limit];
vector<pll> queriesVector;
ll packageLocation[limit];
vector<pair<ll, pll>> build;



ll r[limit];
ll parent[limit];
ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}
void un(ll x, ll y){
    ll xRoot = find(x);
    ll yRoot = find(y);
    if(r[xRoot]<r[yRoot]){
        ll temp = yRoot;
        yRoot = xRoot;
        xRoot = temp;
    }
    parent[yRoot] = xRoot;
    if(r[xRoot] == r[yRoot]) r[xRoot]++;
}


ll boss[limit];
vector<ll> children[limit];
ll ancestor[limit];
bool color[limit];

void makeSet(ll u){
    parent[u] = u;
    r[u] = 1;
}

void LCA(ll u){
    makeSet(u);
    ancestor[find(u)] = u;
    for(auto v : children[u]){
        LCA(v);
        un(u,v);
        ancestor[find(u)] = u;
    }
    color[u] = 1;
    for(auto v : queriesByBoss[u]){
        if(color[v]){
            //cout << "LCA of " << u << " " << v  << " is " << ancestor[find(v)] << endl;
            if(ancestor[find(v)]==u) ancestry[mp(u, v)] = 1;
        }
    }
}

int main(){
    //0 INPUT
    cin >> N >> M;
    ll packageCount = 1;
    loop(m, M){
        ll t;
        cin >> t;
        if(t == 1){
            ll a, b;
            cin >> a >> b;
            build.pb(mp(1, mp(a, b)));

            //LCA priprave
            boss[a] = b;
            children[b].pb(a);
        }else if(t == 2){
            ll a;
            cin >> a;
            build.pb(mp(2, mp(a,0)));
            packageLocation[packageCount] = a;
            packageCount++;
        }else if(t == 3){
            ll x, i;
            cin >> x >> i;
            queriesByPackage[i].pb(x);
            queriesVector.pb(mp(x, i));
        }
    }

    //1 DSU
    //printf("\nPhase 1: DSU\n");
    loop(i, N+10) parent[i] = i;
    loop(i, N+10) r[i] = 1;
    ll packageNum = 1;
    for(auto q : build){
        if(q.fs == 1){
            un(q.sc.fs, q.sc.sc);
        }else{
            ll worker = q.sc.fs;
            for(auto queer : queriesByPackage[packageNum]){
                if(find(queer)==find(worker)){
                    queriesByBoss[queer].pb(worker); //dva vozlišča
                    ans[mp(queer, packageNum)] = 1;
                    //printf("query 3 %d %d was correct, worker: %d, find(q): %d, find(w): %d\n", 
                    //queer, packageNum, worker, find(queer), find(worker));
                }/*else{
                    printf("query 3 %d %d was invalid, worker: %d, find(q): %d, find(w): %d\n", 
                    queer, packageNum, worker, find(queer), find(worker));
                }*/
            }
            packageNum++;
        }
    }
    


    //2 LCA
    loop(i, N+10) parent[i] = i;
    loop(i, N+10) r[i] = 1;
    //printf("\nPhase 2: LCA\n");
    vector<ll> vrhovi;
    loop(i, N) if(boss[i+1]==0) vrhovi.pb(i+1);
    for(auto vrh : vrhovi) LCA(vrh);

    //3 OUTPUT
    //printf("\n");
    for(pll query : queriesVector){
        if(ans[query] == 0){
            cout << "NO" << endl;
        }else{
            ll worker = query.fs;
            ll packageId = query.sc;
            ll secondWorker = packageLocation[packageId];
            if(ancestry[mp(worker, secondWorker)]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}