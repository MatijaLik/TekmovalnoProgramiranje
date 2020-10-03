#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

#define limit 100100

int parent[limit];
vector<int> children[limit];

map<pll, ll> multiplier;
map<pll, ll> weight;
map<pll, ll> cost;

vector<int> sosedi[limit];

ll totalS = 0;

priority_queue<pair<ll, pll>> q;

ll dfs(int node){

    ll leafCount = 0;

    for(auto sosed :  sosedi[node]){
        if(sosed == parent[node]) continue;
        parent[sosed] = node;
        children[node].pb(sosed);
        leafCount += dfs(sosed);
    }

    if(node == 1) return 0;
    
    totalS += max(leafCount, (ll)1)  * weight[mp(node, parent[node])];
    //printf("%lld %lld %lld\n", totalS, multiplier[mp(node, parent[node])] , weight[mp(node, parent[node])]);

    multiplier[mp(node, parent[node])] = max(leafCount, (ll)1);
    ll a = weight[mp(node, parent[node])];
    ll b = floor(weight[mp(node, parent[node])] /2);
    ll potentialLoss = a - b;
    ll prod = multiplier[mp(node, parent[node])] * potentialLoss;

    //prod /= cost[mp(node, parent[node])];
    if(cost[mp(node, parent[node])] == 1) prod *= 2;

    //printf("Pushing prod %lld, nodes %lld %lld\n", prod, node, parent[node]);
    //printf("%lld %lld %lld\n", a, b, potentialLoss);

    q.push(mp(prod, mp(node, parent[node])));

    return max(leafCount, (ll)1);
}



void solve(){
    memset(parent, 0, sizeof parent);
    loop(i, limit) children[i].clear();
    loop(i, limit) sosedi[i].clear();
    q = priority_queue<pair<ll, pll>>();
    totalS = 0;
    
    weight.clear();
    multiplier.clear();
    cost.clear();

    ll n, S;
    cin >> n >> S;

    loop(i, n-1){
        ll a, b, w, c;
        cin >> a >> b >> w >> c;
        weight[mp(a, b)] = w;
        weight[mp(b, a)] = w;
        //edges.pb(mp(a, b));

        cost[mp(a, b)] = c;
        cost[mp(b, a)] = c;

        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    
    parent[1] = 1;
    dfs(1);


    //cout << totalS << endl;
    //printf("S top nbegin %lld\n", totalS);
    int step = 0;
    while(totalS > S){
        //step++;
        pair<ll, pll> p = q.top();
        q.pop();

        ll multi = multiplier[p.sc];
        ll wght = weight[p.sc];

        weight[p.sc] = floor(weight[p.sc]/2);

        totalS -= multi*(wght - weight[p.sc]);
        step += cost[p.sc];

        ll potentialLoss = weight[p.sc] - floor(weight[p.sc]/2);

        ll prod = multi*potentialLoss;
        if(cost[p.sc] == 1) prod *= 2;

        q.push(mp(prod, p.sc));


        //printf("popped %lld %lld --> prod %lld\n", p.sc.fs, p.sc.sc, p.fs);
        //printf("S is now %lld\n", totalS);
        
    }
    cout << step << endl;
    //cout << totalS << endl;
}   




int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
}