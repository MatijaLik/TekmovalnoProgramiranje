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

const int MOD = 1000000007;
#define Nlimit 70

map<pll, ll> color;
vector<pll> edges;
set<pll> pairs;
map<ll, ll> yes;
#define DEBUG 0

int dfs(int depth, int cur, int prev, int goal){
    if(cur==goal)return depth;
    for(auto e : sosedi[cur]){
        if(e==prev)continue;
        int res = dfs(depth+1, e, cur, goal);
        if(res) return res;
    }
    return 0;
}

int dist(int a){
    return dfs(0, a, a, b);
}

int N,  K;
vector<int> sosedi[Nlimit];

void solve(){
    //m=1
    cin >> N >> K;
    loop(i, N-1){
        int a, b;
        cin >> a >> b;
        int w;
        cin >> w;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
        color[mp(a,b)]=w;
        color[mp(b,a)]=w;
    }
    ll ans = 0;
    set<int> mns;
    int mn=inf;
    
    FOR(mask, 0, (1<<(N))-1){
        if(__builtin_popcount(mask)!=K)continue;
        //pobarvaj
        set<int> s;
        for(int i=0;i<edges.size();i++){
            yes.clear();
            if(mask&(1<<i)){
                s.insert(i);
                yes[i]=1;
            }
        }
        int mx = 0;
        //preveri
        FOR(i, 1, N){
            mx = max(mx,dist(i));
        }
        if(mx< mn){
            mns=s;
            mn=mx;
        }


    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}