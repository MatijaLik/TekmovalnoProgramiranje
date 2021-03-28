 
/**
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
#define DEBUG 1

struct sort_y {
    bool operator()(const std::pll &left, const std::pll &right) {
        return left.second < right.second;
    }
};



struct Node{
    Node * leftChild;
    Node * rightChild;
    pll areaX;
    pll areaY;
    int nodeCnt;
    split;

    Node(pll x, pll y, int cnt, int sp){
        areaX = x;
        areaY = y;
        nodeCnt = cnt;
        split = sp;
    };
};

Node nodes[120000];
int space = 0;

Node* build(vector<pll> points, int depth, pll areaX, pll areaY){
    int axis = depth%2;

    if(axis) sort(all(points));
    else sort(all(points), sort_y());

    int mid = points.size()/2;
    pll median = points[mid];
    int split;
    if(axis) split = median.fs;
    else split = median.sc;

    nodes[space] = Node(
        areaX,
        areaY,
        points.size(),
        split
    );

    vector<pll> left(&points[0], &points[mid+1]);
    vector<pll> right(&points[mid+1], points.end());
    nodes[space].leftChild = build(left, depth+1, 
}

void solve(){
    int n;
    cin >> n;

    vector<pll> points;
    vector<pair<pll, pll>> rects; //par<xInterval, yInterval>

    //coordinate compression
    map<int, int> xComp;
    map<int, int> yComp;

    set<int> xSet;
    set<int> ySet;

    loop(i, n){
        int a, b;
        cin >> a >> b;
        points.pb(mp(a, b));
    }

    int m;
    cin >> m;
    loop(i, m){
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        rects.pb(mp(mp(x1, x2), mp(y1, y2)));
    }  

    if(DEBUG){
        printf("compressing...\n");
        for(auto e : points) printf("%lld %lld\n", e.fs, e.sc);
        for(auto e : rects) printf("%lld-%lld %lld-%lld\n",
         e.fs.fs, e.fs.sc, e.sc.fs, e.sc.sc);
    }
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
