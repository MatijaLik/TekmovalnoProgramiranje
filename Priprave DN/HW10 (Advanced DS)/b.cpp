#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 160000
struct node{
    ll lChild;
    ll rChild;
    ll lSize;
    ll rSize;
    ll totalSize;
    node(ll lc, ll rc, ll ls, ll rs) : lChild(lc), rChild(rc), lSize(ls), rSize(rs) {totalSize = lSize + rSize; }
    node() : lChild(-1), rChild(-1), lSize(-1), rSize(-1) {totalSize = lSize + rSize; }
};

ll N;
ll cnt;

node nodes[4*limit];

ll parent[4*limit];
ll sz[4*limit];
ll location[4*limit];
ll answer[limit];

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void un(ll x, ll y){
    ll xRoot = find(x);
    ll yRoot = find(y);
    if(sz[xRoot]<sz[yRoot]){
        ll temp = yRoot;
        yRoot = xRoot;
        xRoot = temp;
    }
    parent[yRoot] = xRoot;
    sz[xRoot]+=sz[yRoot];
}

void explore(ll id, ll left, ll right){
    //printf("exploring id %d; from %d to %d\n", id , left, right);
    node n = nodes[id];
    if(n.lChild==-1){// edge case
        answer[left] = id;
        return;
    }
    explore(n.lChild, left, left+n.lSize-1);
    explore(n.rChild, left+n.lSize, right);
}


int main(){
    memset(sz, 1, sizeof sz);
    cin >> N;
    loop(i, N){
        parent[i+1] = i+1;
        location[i+1] = i+1;
        nodes[i+1] = {-1, -1, 1, 0};
    }
    cnt = N;
    loop(i, N-1){
        cnt++;
        ll a, b;
        cin >> a >> b;
        ll lc = location[find(a)];
        ll rc = location[find(b)];
        ll ls = nodes[lc].totalSize;
        ll rs = nodes[rc].totalSize;

        un(a, b);
        location[find(a)] = cnt;
        nodes[cnt] = {lc, rc, ls, rs};
        //cout << nodes[cnt].totalSize << endl;
        //printf("Node %d, lc %d size %d, rc %d size %d\n", cnt, lc, ls, rc, rs);
    }    
    //cout << "#######" << endl;
    explore(cnt, 1, N);
    FOR(i, 1, N+1){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}