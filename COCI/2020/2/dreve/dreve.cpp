/**
 * Author: MatijaL
 * Time: 2020-11-14 16:42:52
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
#define inf 4000000005
#define mod 1000000007

#define limit 100100

ll N , M;
ll parent[limit];
ll sz[limit];
ll w[limit];

vector<pll> antene;

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void un(ll x, ll y){
    x = find(x);
    y = find(y);
    if(sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];

    w[x] = max(w[x], w[y]);
}

ll cost(ll a, ll b){
    a = find(a);
    b = find(b);

    return w[a] + w[b];
}

void solve(){
    cin >> N;
    vector<ll> t(N+10);
    loop(i, N) cin >> t[i+1];

    FOR(i, 1, N){
        parent[i] = i;
        sz[i] = 1;
        w[i] = t[i]; 
    }

    vector<pll> edges;
    ll ans = 0;
    loop(i, N-1){
        int a, b;
        cin >> a >> b;
        edges.pb(mp(a,b));
    }

    loop(i, N-1){

        //probaj vsako povezavo
        ll best = 0;
        ll minCost = inf;

        FOR(id, 0, N-2){
            pll e = edges[id];
            int a = e.fs;
            int b = e.sc;

            if(find(a) == find(b)) continue;

            ll cs = cost(a, b);
            if(cs < minCost){
                minCost = cs;
                best = id;
            }
        }

        pll e = edges[best];
        int a = e.fs;
        int b = e.sc;
        //printf("best is %d %d with cost %lld\n", a, b, cost(a, b));
        ans += cost(a, b);
        un(a, b);
        
        
        
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
