/**
 * Author: MatijaL
 * Time: 2020-11-03 08:56:34
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

#define limit 2001000

int N;
int par[limit];
vector<int> kids[limit];

ll a[limit];

ll toProp[limit];

ll dfs(int node){
    ll sum = a[node];
    vector<int> w;
    for(auto k : kids[node]){
        ll t = dfs(k);
        sum += t;
        w.pb(t);
    }

    

    return sum;
}

void solve(){
    cin >> N;
    FOR(i, 2, N){
        int p;
        cin >> p;
        par[i] = p;
        kids[p].pb(i);
    }
    FOR(i, 1, N){
        ll e;
        cin >> e;
        a[i] = e;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
