/**
 * Author: MatijaL
 * Time: 2020-10-17 19:31:33
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
#define inf 100000005
#define mod 1000000007
const int limit = 200100;

int N;
vector<int> sosedi[limit];
ll cs[limit];
int par[limit];

ll dfs(int node, int prev){
    ll sum = node;
    par[node] = prev;
    for(auto sosed : sosedi){
        if(sosed == prev) continue;
        sum += dfs(sosed, node);
    }
    cs[node] = sum;
    return sum;
}

ll total;
vector<pll> v;
ll best = inf*inf;
void preCalc(){
    FOR(i, 2, N){
        ll B = cs[i];
        ll A = total-B;
        v.pb(mp(A, i));
    }
    sort(all(v));
}
void solve(){
    cin >> N;
    loop(i, N-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    dfs(1, 0);
    total = cs[1]; 
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
