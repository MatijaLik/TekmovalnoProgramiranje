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
#define inf 1'000'000'000
#define mod 1000000007

#define DEBUG 0

int N, M, K;
ll edges[100][100];
ll ans[100][100];

void dijkstra(int a){
    ll dist[100][100];
    loop(i, 100) loop(j, 100) dist[i][j] = inf;
    loop(j, 100) dist[a][j] = 0;

    bool visited[100][100];
    memset(visited, 0, sizeof visited);
    priority_queue<array<ll, 3>> q;
    q.push({0, 0, a});
    while(!q.empty()){
        array<ll, 3> p = q.top();
        q.pop();
        int node = p[2];
        int len = p[1];
        ll distanc = -p[0];
        if(visited[node][len]) continue;
        visited[node][len] = true;

        if(len==K) continue;
        FOR(nxt, 1, 99){
            if(edges[node][nxt]!=inf){
                ll t = edges[node][nxt];
                if(dist[nxt][len+1] > distanc + t){
                    dist[nxt][len+1] = distanc + t;
                    q.push({-dist[nxt][len+1],len+1, nxt});
                }
            }
        }
    }
    loop(node, 100){
        if(node==a) {ans[a][a]=0;continue;}
        loop(len, K+1){
            if(ans[a][node]==-1&&dist[node][len]!=inf) ans[a][node] = dist[node][len];
            ans[a][node] = min(ans[a][node], dist[node][len]);
        }   
    }
    /*
    if(DEBUG){
        printf("Dijsktra from node %d\n", a);
        FOR(i, 1, N) printf("Len to %d -> %lld\n", i, ans[a][i]);
        printf("///////\n");
    }*/
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    loop(i, 100)loop(j, 100) edges[i][j]=inf;
    cin >> N >> M;
    loop(i, M){
        ll a, b, t;
        cin >>a>>b>>t;
        edges[a][b] = min(edges[a][b], t);
    }
    int q;
    cin >> K >> q;
    K = min(K, N);
    loop(i, 100) loop(j, 100) ans[i][j] = -1;
    FOR(i, 1, N) dijkstra(i);
    loop(i, q){
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
}