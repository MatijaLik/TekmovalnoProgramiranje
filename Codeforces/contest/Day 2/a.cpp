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
#define inf 1000000000
#define mod 1000000007

#define nlimit 100100

const double EPS = 1e-7;

struct Edge{
    int a, b, k;

    Edge(){
        a = 0;
        b = 0;
        k = 0;
    }
    Edge(ll _a, ll _b, ll _k){
        a = _a;
        b = _b;
        k = _k;
    }

    bool operator < (const Edge& other) const{
        if(a != other.a) return a < other.a;
        if(b != other.b) return b < other.b;
        else return k < other.k; 
    }
};

struct Leq{
    ll c, k;

    Leq(){
        c = 0;
        k = 0;
    }
    Leq(ll a, ll b){
        c = a;
        k = b;
    }

    Leq negate(int i){
        return Leq{i-c, -k};
    }

    double equate(Leq other){
        if(k == other.k) return -inf;
        return (double)(other.c - c) / (double) (k - other.k);
    }

    bool operator ==(Leq other){
        return (c == other.c and k == other.k);
    }

    double assign(double x){
        return c + k*x;
    }
}; 

double mid(double l, double r){return (l+r)/2;}

ll N, M;
vector<Edge> edges;
vector<Edge> edgesToNode[nlimit];
map<Edge, bool> edgeUsed;

double nodeValue[nlimit];
Leq nodeEq[nlimit];

bool collision = 0;
double collisionX;

vector<int> visited;
set<int> visitedS;

void dfs(int node, Leq eq){

    if(visitedS.count(node) == 0){
        visited.pb(node);
        visitedS.insert(node);
    }

    //printf("DFS node %lld -> %lld + %lldx\n", node, eq.c, eq.k);

    //preveri collision
    if(not(nodeEq[node] == Leq() or nodeEq[node] == eq or collision)){
        collisionX = nodeEq[node].equate(eq);
        //printf("Collision x -> %f\n", collisionX);
        collision = 1;
    }else nodeEq[node] = eq;
   
    
    for(auto povezava : edgesToNode[node]){
        if(edgeUsed[povezava]) continue;
        edgeUsed[povezava] = 1;

        ll weight = povezava.k;
        ll other;
        if(povezava.a == node) other = povezava.b;
        else other = povezava.a;  

        dfs(other, eq.negate(weight));
    }
}

double evaluate(double x){
    double sum = 0;
    
    //for each node
    for(auto node : visited){
        sum += abs(nodeEq[node].assign(x));
    }
    return sum;
}

void solve(){
    cin >> N >> M; 
    loop(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb(Edge{a, b, c});
        edgesToNode[a].pb(Edge{a, b, c});
        edgesToNode[b].pb(Edge{a, b, c});
    }

    FOR(node, 1, N){
        if(not(nodeEq[node] == Leq())) continue;
        dfs(node, Leq{0, 1});

        if(collisionX == -inf){
            cout << "NO" << endl;
            return;
        }

        //vsem obiskanim daj value
        if(collision){
            for(auto visitedNode : visited)
                nodeValue[visitedNode] = nodeEq[visitedNode].assign(collisionX);
        }else{
            //binary search
            double l = -inf;
            double r = inf;
            double m;
            loop(q, 55){
                //printf("%.6f %.6f\n", l, r);
                m = mid(l, r);
                if(evaluate(m) >= evaluate(m+EPS)) l = m;
                else r = m; 
            }
            for(auto visitedNode : visited)
                nodeValue[visitedNode] = nodeEq[visitedNode].assign(m);
        }
        

        collision = 0;
        collisionX = 0;
        visitedS.clear();
        visited.clear();
    }

        
    //verify graph
    bool gud = 1;
    for(auto edge : edges){
        double request = edge.k;
        double provided = nodeValue[edge.a] + nodeValue[edge.b];
        if(abs(request-provided) > EPS){
            gud = 0;
            //printf("error at %lld %lld\n", edge.a, edge.b);
            //printf("%.3f ->>> %.3f\n", request, provided);
            cout << "NO" << endl;
            return;
        }    
    }

    cout << "YES" << endl;
    FOR(node, 1, N){
        printf("%.6f ", nodeValue[node]);
    }
    cout << endl;
    
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}