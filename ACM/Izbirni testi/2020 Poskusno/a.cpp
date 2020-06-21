#include <bits/stdc++.h>
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
#define debug(x) cout << "# " << x << endl

#define limit 1100

ll N, M;
ll X, Y;

vector<pair<pll, pll>> edges;

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

bool custom_sort(pair<pll, pll> a, pair<pll, pll> b){
    ll costA = max(a.sc.fs*X, a.sc.sc*Y);
    ll costB = max(b.sc.fs*X, b.sc.sc*Y);
    return costA < costB;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> X >> Y;
    loop(i, M){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        edges.pb(mp(mp(a, b), mp(c, d)));
    }

    loop(i, N) parent[i+1] = i+1;

    //sortiraj edge
    sort(all(edges), custom_sort);

    //izpisi vse
    /*
    loop(i, M){
        pair<pll, pll> a = edges[i];
        printf("%lld %lld\n", a.fs.fs, a.fs.sc);
    }*/

    //gradi drevo
    ll maxA = 0;
    ll maxB = 0;

    loop(i, M){
        pair<pll, pll> e = edges[i];
        ll nodeA = e.fs.fs;
        ll nodeB = e.fs.sc;
        
        ll costA = e.sc.fs;
        ll costB = e.sc.sc;

        if(find(nodeA) != find(nodeB)){
            //printf("Building %lld %lld\n", nodeA, nodeB);
            un(nodeA, nodeB);
            maxA = max(maxA, costA);
            maxB = max(maxB, costB);
        }
    }

    //preveri povezanost
    int b = find(1);
    FOR(i, 1, N){
        if(b != find(i)){
            cout << -1 << endl;
            return 0;
        }
    }

    printf("%lld\n", X*maxA + Y*maxB);

}  