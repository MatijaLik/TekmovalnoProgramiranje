#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define plll pair<ll, pair<ll, ll >>
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
#define limit 100010

ll N , M;
ll parent[limit];
ll sz[limit];


ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

ll un(ll x, ll y){
    x = find(x);
    y = find(y);
    if(sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    ll t = sz[x];
    sz[x] += sz[y];
    return sz[y]*t;
}


int main(){
    loop(i, limit) sz[i] = 1;
    cin >> N >> M;
    priority_queue <plll> q;
    ll w[N+10];
    loop(i, N) cin >> w[i+1];
    loop(i, N) parent[i+1] = i+1;
    loop(i, M){
        ll a , b;
        cin >> a >> b;
        q.push(mp(min(w[a], w[b]),mp(a,b)));
    }
    ll moves = 0;
    ll ans = 0;
    while(moves < N-1){
        plll p = q.top();
        q.pop();
        ll w = p.fs;
        ll a = p.sc.fs;
        ll b = p.sc.sc;
        if(find(a)==find(b))continue;
        moves++;
        ll h = un(a,b);
        ans+= w*h;
        //cout << "union " << a << " " << b << endl;
        //cout << w <<  " " << h <<  endl;
    }
    ans *= 2;
    double out = (double)ans/(double)(N*(N-1));
    printf("%.6f\n", out);
    return 0;
}