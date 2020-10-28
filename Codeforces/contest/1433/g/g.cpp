/**
 * Author: MatijaL
 * Time: 2020-10-22 20:00:22
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

#define limit 1050

int N, M, K;
vector<pll> sosedi[limit];
vector<pll> edges;
map<pll, ll> edgeCost;
map<pll, ll> cnt;
ll totalCost = 0;

void dijkstra(int start, int end){
    ll dist[limit];
    loop(i, N+1) dist[i] = inf;
    dist[start] = 0;

    ll prev[limit];

    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(mp(0, start));

    while(!q.empty()){
        pll p = q.top();
        q.pop();
        int node = p.sc;
        int d = p.fs;
        if(d != dist[node]) continue;

        //cout << node << endl;
        for(auto sp : sosedi[node]){
            int w = sp.sc;
            int sosed = sp.fs;
            if(w + d < dist[sosed]){
                dist[sosed] = w+d;
                prev[sosed] = node;
                q.push(mp(dist[sosed], sosed));
            }
        }
    }
    
    int cur = end;
    while(cur != start){
        //cout << cur << endl;
        int a = cur;
        int b = prev[cur];

        cnt[mp(min(a, b), max(a,b))]++;
        totalCost += edgeCost[mp(min(a, b), max(a, b))];

        cur = prev[cur];
    }
}

void solve(){
    cin >> N >> M >> K;
    loop(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        sosedi[a].pb(mp(b, c));
        sosedi[b].pb(mp(a, c));
        edges.pb(mp(min(a,b), max(a, b)));
        edgeCost[mp(min(a, b), max(a, b))] = c;
    }

    loop(i, K){
        int a, b;
        cin >> a >> b;
        dijkstra(a, b);
    }
    ll best = 0;
    for(auto e : edges){
        best = max(best, cnt[e]*edgeCost[e]);
    }
    cout<< best << endl;
    cout << totalCost - best << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
