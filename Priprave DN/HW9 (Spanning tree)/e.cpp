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
#define limit 100010

ll N, M;    
ll r[limit];
ll parent[limit];
ll ancestor[limit];
ll color[limit];


vector<pair<int,pll>> build; //queriji tipa 1 in 2;
vector<pll> aq; //  vsi pozivi
vector<ll> q1[limit]; //kljuc je lokacija paketa
ll pl[limit]; //kje je paket

vector<ll> children[limit]; // za DAG
set<pll> q2; // queriji drugic
bool hasBoss [limit];
vector<ll> vrhovi;

map<pll, bool> ans; //odgovori

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

void LCA(ll u){
    debug(u);
    ancestor[find(u)] = u;
    for(auto v : children[u]){
        LCA(v);
        un(u,v);
        ancestor[find(u)] = u;
    }
    color[u] = 1;
    for(auto v : children[u]){
        if(q2.count(mp(u,v))){
            if(color[v]){
                cout << "LCA of " << u << " " << v  << " is " << ancestor[find(v)] << endl;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    ll nop = 1;//numOfPkg
    loop(i, M){
        int t;
        cin >> t;
        if(t==1){
            ll a, b;
            cin >> a >> b;
            build.pb(mp(1, mp(a,b)));
            hasBoss[a] = 1;
            children[b].pb(a);
        }else if(t==2){
            ll a;
            cin >> a;
            build.pb(mp(2, mp(a, 0)));
            pl[nop] = a;
            nop++;
        }else if(t==3){
            int a, b;
            cin >> a >> b;
            b = pl[b];
            q1[b].pb(a);
            aq.pb(mp(a,b));
            cout << "query " << a << " " << b << endl;
        }
    }

    //najdemo vrhove
    FOR(i,1, N+1)if(hasBoss[i]==0) vrhovi.pb(i);

    //prvic gremo skozi z DSU
    loop(i, N+5) parent[i] = i;
    for(auto q : build){
        if(q.fs==1){
            un(q.sc.fs, q.sc.sc);
            cout << "union " << q.sc.fs << " " << q.sc.sc << endl;
        }else if(q.fs==2){
            ll pkg = q.sc.fs; //package odlozimo na node pkg
            for(auto request : q1[pkg]){
                if(find(request) == find(pkg)){
                    q2.insert(mp(request, pkg));
                    cout << "gucci " << request << " " << pkg << endl;
                }else{
                    cout << "aborting " << request << " " << pkg << endl;
                }
            }
        }
    }

    //resetiraj
    loop(i, N+5) parent[i] = i;
    loop(i, N+5) r[i] = 0;
    //drugic pa z LCA
    for(auto vrh: vrhovi) {
        LCA(vrh);
    }
    for(auto poziv : aq){
        if(ans[poziv]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}