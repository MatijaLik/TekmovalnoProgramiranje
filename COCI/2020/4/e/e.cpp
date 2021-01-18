/**
 * Author: MatijaL
 * Time: 2021-01-17 11:59:52
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
struct Edge{
    int x, y;
    int w;
    Edge(int a, int b, int c){
        x = a;
        y = b;
        w = c;
    }
};
void solve(){
    int N, M;
    cin >> N >> M;
    pll start, end;
    char grid[N][M];
    loop(i, N){
        string s;
        cin >> s;
        loop(j, M){
            char c = s[j];
            grid[i][j] = c;

            if(c == 'o') start = mp(i, j);
            if(c == 'x') end = mp(i, j);
        }
    }
    vector<Edge> sosedi[N][M];
    loop(i, N)loop(j, M){
        char c = grid[i][j];
        if(c == 'x') continue;
        bool b = c == 'o'; 


        int mask[4] = {1, 1, 1, 1};
        if(c == 'v' or b) mask[0] = 0;
        if(c == '<' or b) mask[1] = 0;
        if(c == '^' or b) mask[2] = 0;
        if(c == '>' or b) mask[3] = 0;
        
        if(i != N-1) sosedi[i][j].pb(Edge(i+1, j, mask[0]));
        if(i != 0) sosedi[i][j].pb(Edge(i-1, j, mask[2]));
        if(j != M-1) sosedi[i][j].pb(Edge(i, j+1, mask[3]));
        if(j != 0) sosedi[i][j].pb(Edge(i, j-1, mask[1]));
    }

    int dist[N][M];
    loop(i, N)loop(j, M) dist[i][j] = inf;
    dist[start.fs][start.sc] = 0;

    pll prev[N][M];
    bool visited[N][M];
    memset(visited, 0, sizeof visited);



    deque<pll> q;
    q.push_front(start);
    while(!q.empty()){
        pll cur = q.front();
        q.pop_front();

        visited[cur.fs][cur.sc] = true;
        if(cur == end) break;
        for(auto e : sosedi[cur.fs][cur.sc]){
            int i = e.x;
            int j = e.y;
            int w = e.w;
            if(visited[i][j]) continue;
            if(dist[i][j] > dist[cur.fs][cur.sc] + w){
                dist[i][j] = dist[cur.fs][cur.sc] + w;
                prev[i][j] = cur;
                if(w == 1) q.push_back(mp(i, j));
                else q.push_front(mp(i, j));
            }
        }
        
    }
    cout << dist[end.fs][end.sc] << endl;

    pll cur = end;
    pll next = prev[cur.fs][cur.sc];
    while(next != start){
        if(dist[cur.fs][cur.sc] != dist[next.fs][next.sc]){
            if(cur.fs == next.fs+1) grid[next.fs][next.sc] = 'v';
            if(cur.fs == next.fs-1) grid[next.fs][next.sc] = '^';
            if(cur.sc == next.sc+1) grid[next.fs][next.sc] = '>';
            if(cur.sc == next.sc-1) grid[next.fs][next.sc] = '<';
        }
        cur = next;
        next = prev[next.fs][next.sc];

    }
    loop(i, N){
        loop(j, M){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
