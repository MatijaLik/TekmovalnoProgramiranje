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
#define limit 100010

map<pll, ll> ans;
vector<ll> sosedi[limit];
ll N;
vector<pll> edges;
bool svic = 0;
ll bot = 0;
ll top = N-2;

set<ll> visited;
ll sub[limit];
void DFS(ll node){
    visited.insert(node);
    int maxS = 0;
    int maxV = 0;
    for(auto sosed: sosedi[node]){
        if(visited.count(sosed)==0){
            if(sub[sosed]> maxV){
                maxV = sub[sosed];
                maxS = sosed;
            }
        
        }
    }
    int sosed = maxS;
    //printf("DFs node %d sosed %d state %d , bot %d, top %d\n", node, sosed, svic, bot, top);
            if(svic){
                
                ans[mp(sosed, node)] = top;
                ans[mp(node, sosed)] = top;
                top--;
                svic = 0;
            }else{
                ans[mp(sosed, node)] = bot;
                ans[mp(node, sosed)] = bot;
                bot++;
                svic = 1;
            }
            DFS(sosed);
}

int DFS1( int node){
    visited.insert(node);
    sub[node] = 1;
    for(auto sosed: sosedi[node]){
        if(visited.count(sosed)==0){
            sub[node] += DFS1(sosed);
        }
    }
    return sub[node];
}

int main(){
    cin >> N;
    top = N-2;
    loop(q, N-1){
        ll a, b;
        cin >> a >> b;
        edges.pb(mp(a,b));
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    DFS1(1);
    visited.clear();
    DFS(1);
    for(auto edge : edges){
        cout << ans[edge] << endl;
    }
}