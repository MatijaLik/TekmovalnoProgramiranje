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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 2000010

ll N, M, S;
set<pll> usedEdges;
set<ll> visited;
vector<ll> sosedi[limit];

ll ans = 0;

void DFS(ll node){
    debug(node);
    visited.insert(node);
    ll paths = 0;
    for(auto sosed : sosedi[node]){
        pll edge = mp(min(node, sosed), max(node, sosed));
        if(visited.count(sosed)==0 and usedEdges.count(edge)==0){
            paths++;
        }
    }
    if(paths == 0){
        ans++;
        cout << "nah fam" << endl;
    }
    
    else{
        for(auto sosed : sosedi[node]){
        pll edge = mp(min(node, sosed), max(node, sosed));
            if(visited.count(sosed)==0 and usedEdges.count(edge)==0){
                usedEdges.insert(edge);
                DFS(sosed);
            }
        }
    }
    cout << "ended " << node << endl;
    visited.erase(node);
}


int main(){
    cin >> N >> M >> S;
    loop(i, M){
        ll a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    DFS(S);
    cout << ans << endl;
}