#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
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
#define inf 1000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 200010
ll N;
vector<ll> sosedi[limit];
int color[limit];

ll parent[limit];
ll down[limit];
ll adj[limit];

ll DFS(ll node, ll prev){
    ll sum = color[node];
    for(ll sosed : sosedi[node]){
        if(sosed == prev) continue;
        parent[sosed] = node;
        ll a = DFS(sosed, node);
        if(a>0) sum +=a;
    }
    return down[node] = sum;
}

void DFS2(ll node, ll prev){
    //debug(node);
    ll res;
    if(node == 1){
        res = down[node];
    }else{
        ll par = parent[node];
        ll self = down[node];
        if(adj[par]>self){
            res = adj[par] + self;
            if(self > 0) res-=self;
        }else{
            res = down[node];
        }
        
    }
    
    adj[node] = res;
    for(ll sosed : sosedi[node]){
        if(sosed == prev) continue;
        DFS2(sosed, node);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    loop(i, N){
        ll temp;
        cin >> temp;
        if(temp) color[i+1] = 1;
        else color[i+1] = -1;
    }
    loop(i, N-1){
        ll a, b;
        cin >> a>> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    DFS(1, 0);
    DFS2(1, 0);
    //FOR(i, 1, N+1) cout << down[i] << " ";
    //cout << endl;
    FOR(i, 1, N+1) cout << adj[i] << " ";
    cout << endl;
}