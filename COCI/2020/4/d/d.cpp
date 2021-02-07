/**
 * Author: MatijaL
 * Time: 2021-01-16 16:53:13
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
#define limit 1500
vector<int> sosedi[limit];
pll up[limit][12];
int dep[limit];
map<pll, int> W;


void dfs(int node, int prev){
    up[node][0] = mp(prev, W[mp(node, prev)]);
    if(node != 1) dep[node] = dep[prev] + 1;
    for(auto e :sosedi[node]){
        if(e == prev) continue;
        dfs(e, node);
    }
}
int ans  = 0;
int n, k;

void test(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);

    ll td = dep[a] + dep[b];
   
    int oga = a;
    int ogb = b;
    
    ll mxa = 0;
    ll mxb = 0;
    ll diff = abs(dep[a] - dep[b]);
    //spravi na isti nivo
    int cur = b;
    for(int e = 11; e >= 0; e--){
        if((1<< e) > diff) continue;

        mxb = max(mxb, up[cur][e].sc);
        cur = up[cur][e].fs;
        diff -= (1 << e);
    }
    

    //najdi LCA
    b = cur;
    
    if(a!=b){
        for(int e = 11; e >= 0; e--){
            if(up[b][e].fs == up[a][e].fs) continue;

            mxb = max(mxb, up[b][e].sc);
            mxa = max(mxa, up[a][e].sc);

            a = up[a][e].fs;
            b = up[b][e].fs;
        }
        mxb = max(mxb, up[b][0].sc);
        mxa = max(mxa, up[a][0].sc);

        a = up[a][0].fs;
        b = up[b][0].fs;
    }

    td -= 2*dep[a];// a je zdaj LCA
    int mx = max(mxa, mxb);
    

    //printf("%d %d| LCA %d| w %d | mx - l%d\n", oga, ogb, a, mx, mx - td);

    if(mx - td >= k) ans++;
    return;
}

void solve(){
    cin >> n >> k;
    loop(i, n-1){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
        W[mp(a, b)] = w;
        W[mp(b, a)] = w;
    }
    W[mp(1, 1)] = 0;
    dep[1] = 0;
    dfs(1, 1);

    //binary lifting
    FOR(i, 1, n){
        FOR(e, 1, 11){
            up[i][e] = mp(
                    up[up[i][e-1].fs][e-1].fs,   
                    max(up[i][e-1].sc, up[up[i][e-1].fs][e-1].sc)
            );

        }
    }


    FOR(i, 1, n){
        FOR(j, 1, n){
            if(i>=j) continue;
            test(i, j);
        }
    }
    cout << 2*ans << endl; 
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
