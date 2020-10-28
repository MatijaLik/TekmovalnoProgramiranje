/**
 * Author: MatijaL
 * Time: 2020-10-04 18:05:01
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
#define inf 3000000005
#define mod 1000000007

struct Point{
    ll x, y;
    ll id;
    Point(ll a, ll b, ll i){x=a;y=b;id=i;}
    ll dist(Point &other){
        return abs(x - other.x) + abs(y - other.y);
    }
    ll xDist(Point &other){
        return abs(x - other.x);
    }
    ll yDist(Point &other){
        return abs(y - other.y);
    }
    ll bdist(Point &other){
        return min(xDist(other), yDist(other));
    }
};
bool sortByX(Point &a, Point &b){
    return a.x < b.x;
}
bool sortByY(Point &a, Point &b){
    return a.y < b.y;
}
struct Edge{
    ll node, weight;
    Edge(ll n, ll w) : node(n), weight(w){} 
};
int solve(){
    int N, M;
    cin >> N >> M;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    Point S = Point(sx, sy, 0);
    Point F = Point(fx, fy, 1);

    vector<Point> p;
    vector<Edge> E[M+2];
    loop(i, M){
        int a, b;
        cin >> a >> b;
        p.pb(Point(a, b, i+2));
    }

    sort(all(p), sortByX);
    loop(i, M-1){
        Point f = p[i];
        Point s = p[i+1];

        E[f.id].pb(Edge(s.id, f.xDist(s)));
        E[s.id].pb(Edge(f.id, s.xDist(f)));
    }

    sort(all(p), sortByY);
    loop(i, M-1){
        Point f = p[i];
        Point s = p[i+1];

        E[f.id].pb(Edge(s.id, f.yDist(s)));
        E[s.id].pb(Edge(f.id, s.yDist(f)));
    }

    loop(i, M){
        Point u = p[i];
        E[0].pb(Edge(u.id, S.bdist(u)));
        E[u.id].pb(Edge(0, u.dist(S)));

        E[u.id].pb(Edge(1, u.dist(F)));

    }

    E[0].pb(Edge(1, S.dist(F)));
    E[1].pb(Edge(0, F.dist(S)));

    ll d[M+2];
    loop(i, M+2) d[i] = inf;
    d[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(mp(0, 0));
    set<int>visited;
    while(!q.empty()){
        pll pa = q.top();
        q.pop();
        int node = pa.sc;
        int dist = pa.fs;
        if(dist != d[node]) continue;
        if(visited.count(node)) continue;
       // printf("Visited %d, dist %d\n", node, dist);
        visited.insert(node);
        for(auto psosed : E[node]){
            int sosed = psosed.node;
            int add = psosed.weight;
            
            if(d[sosed] > dist + add){
        //        printf("Pushing %d | dist %d\n", sosed, add);
                d[sosed] = dist + add;
                q.push(mp(d[sosed], sosed));
            }
            
        }
    }

    return d[1];
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    while(t--)cout <<  solve() << endl;   
}
