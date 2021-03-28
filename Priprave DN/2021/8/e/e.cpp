/**
 * Author: MatijaL
 * Time: 2021-02-17 16:22:02
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

#define limit 200400
void solve(){
    int n, m,k; 
    cin >> n >> m >> k;
    vector<pll> cesta[limit];
    vector<pll> tir;
    loop(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        cesta[a].pb(mp(b, c));
        cesta[b].pb(mp(a, c));
    }

    loop(i, k){
        ll a, c;
        cin >> a >> c;
        tir.pb(mp(a,c));
    }


    bool visited[limit];
    ll dist[limit];
    int used = 0;
    FOR(i, 1, n){
        visited[i] = false;
        dist[i] = inf*1LL*inf; 
    }
    assert(k+m < 400100);
    priority_queue<pair<double, pll>> q;
    q.push(mp(0,mp(1,1)));

    while(!q.empty()){
        assert(q.size()<400100);
        auto p = q.top();
        q.pop();

        double d = -p.fs;
        int u = p.sc.fs;
        int v = p.sc.sc;


        if(visited[v]) continue;

       // printf("%d %d | %F\n", u, v, d);

        //poglej ce je to zeleznica
        if(floor(d) < d-0.01){
            used++;
            d = floor(d);
        }
        
        dist[v] = d;
        visited[v] = true;

        //poglej vse povezave naprej
        for(auto e : cesta[v]){
            if(visited[e.fs]) continue;
            q.push(mp(-(dist[v] + e.sc), mp(v, e.fs)));
        }

        //tiri
        if(v == 1){
            for(auto e :tir){
                q.push(mp(-(e.sc + 0.5), mp(1, e.fs)));
            }
        }
    }

    cout << k - used << endl; 
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
