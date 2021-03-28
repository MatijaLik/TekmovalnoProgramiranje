/**
 * Author: MatijaL
 * Time: 2021-03-27 13:26:20
**/
//#pragma GCC optimize("Ofast")
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

#define limit 200000
#define DEBUG 0

ll r[limit];
ll parent[limit];

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}
void un(ll x, ll y){
    ll xRoot = find(x);
    ll yRoot = find(y);
    if(xRoot == yRoot) return;
    if(r[xRoot]<r[yRoot]){
        ll temp = yRoot;
        yRoot = xRoot;
        xRoot = temp;
    }
    parent[yRoot] = xRoot;
    if(r[xRoot] == r[yRoot]) r[xRoot]++;
}

void solve(){
    int n, m;
    cin >> n >> m;

    FOR(i, 0, n){
        r[i] = 0;
        parent[i] = i;
    }

    vector<pll> brati;
    vector<int> cigani[limit];

    map<pll, int> adj;

    FOR(i, 1, m){
        int a, b, p;
        cin >> a >> b >> p;
        if(p == 1){
            brati.pb(mp(a, b));
        }
        if(p == 0){
            cigani[a].pb(b);
            cigani[b].pb(a);
            p = -1;
        }

        adj[mp(a, b)] = p;
        adj[mp(b, a)] = p;
    }

    //1
    for(auto e : brati){
        int a = e.fs;
        int b = e.sc;
        un(a, b);
    }

    //vsi oblaki
    set<int> oblaki;
    map<int, int> id;
    int x = 0;
    FOR(i, 1, n){
        if(!oblaki.count(find(i))){
            id[find(i)] = x;
            x++;
            oblaki.insert(find(i));
        }
    }

    vector<int> nodes[x]; //za vsak oblak vozlisce
    FOR(i, 1, n){
        nodes[id[find(i)]].pb(i);
    }
    //izpisi vse oblake
    if(DEBUG)for(auto e : nodes){
        print(e);
    }

    //2 preverimo znotraj oblaka
    FOR(i, 0, x-1){
        int os = nodes[i].size();
        for(auto a : nodes[i])for(auto b : nodes[i]){
            if(a == b) continue;
            if(adj[mp(a, b)] != 1){

                if(DEBUG)printf("%d %d are in same cloud but not friends!\n", a, b);
                printf("NE\n");
                return;
            }
        }
    }


    //4 in pol 3
    FOR(i, 0, x-1){
        set<int> enemies;
        for(auto e : nodes[i]){
            for(auto sovrag : cigani[e]){

                if(find(e) == find(sovrag)){
                    if(DEBUG)printf("%d %d are in same cloud but are enemies!\n", e, sovrag);
                    printf("NE\n");
                    return;
                }
                enemies.insert(id[find(sovrag)]);
            }
        }

        if(enemies.size() >= 2){
            if(DEBUG)printf("Cloud %d has too many enemies!\n", i);
            printf("NE\n");
            return;
        }

        if(enemies.empty()) continue;

        //3. pogoj
        int ecloud = *enemies.begin();

        for(auto a : nodes[i]){
            for(auto b : nodes[ecloud]){
                if(adj[mp(a, b)] != -1){
                    if(DEBUG)printf("%d %d are in enemy clouds but are not enemies!\n", a, b);
                    printf("NE\n");
                    return;
                }
            }
        }
    }

    printf("DA\n");
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
