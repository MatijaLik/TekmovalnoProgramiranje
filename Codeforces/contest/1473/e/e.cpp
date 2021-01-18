/**
 * Author: MatijaL
 * Time: 2021-01-14 15:35:19
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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

#define limit 800100
inline int f(int a, int b){
    return 4*a + b;
}
void solve(){
    int V, E;
    cin >> V >> E;
    vector<pll> sosedi[limit];
    
    loop(i, E){
        int a, b;
        cin >> a >> b;
        ll w;
        cin >> w;

        //crni
        sosedi[f(a, 0)].pb(mp(f(b, 0), w));
        sosedi[f(a, 1)].pb(mp(f(b, 1), w));
        sosedi[f(a, 2)].pb(mp(f(b, 2), w));
        sosedi[f(a, 3)].pb(mp(f(b, 3), w));
        sosedi[f(b, 0)].pb(mp(f(a, 0), w));
        sosedi[f(b, 1)].pb(mp(f(a, 1), w));
        sosedi[f(b, 2)].pb(mp(f(a, 2), w));
        sosedi[f(b, 3)].pb(mp(f(a, 3), w));

        //zelene
        sosedi[f(a, 0)].pb(mp(f(b, 1), 0));
        sosedi[f(a, 2)].pb(mp(f(b, 3), 0));
        sosedi[f(b, 0)].pb(mp(f(a, 1), 0));
        sosedi[f(b, 2)].pb(mp(f(a, 3), 0));

        //modre
        sosedi[f(a, 0)].pb(mp(f(b, 2), 2*w));
        sosedi[f(a, 1)].pb(mp(f(b, 3), 2*w)); 
        sosedi[f(b, 0)].pb(mp(f(a, 2), 2*w));
        sosedi[f(b, 1)].pb(mp(f(a, 3), 2*w));

        //rumene
        sosedi[f(a, 0)].pb(mp(f(b, 3), w));
        sosedi[f(b, 0)].pb(mp(f(a, 3), w));
    }

    ll dist[limit];
    loop(i, limit) dist[i] = inf*1LL*inf;

    dist[4] = 0;
    priority_queue<pll> q;
    q.push(mp(0,4));
    
    bool visited[limit];
    memset(visited, 0, sizeof visited);
    
    while(!q.empty()){
        pll e = q.top();
        q.pop();

        ll node = e.sc;
        if(visited[node]) continue;
        visited[node] = true;

        for(auto sosed : sosedi[node]){
            ll w = sosed.sc;
            ll next = sosed.fs;
            if(dist[next] > w + dist[node]){
                dist[next] = w + dist[node];
                q.push(mp(-dist[next], next));
            }
        }
    }
    FOR(i, 2, V) cout << dist[f(i, 3)] << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
     solve();   
}
