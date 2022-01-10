/**
 * Author: MatijaL
 * Time: 2021-11-18 23:23:40
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
#define limit 70000
int N;
vector<int> adj[limit];
map<int, int> m;
map<pll, int> s;
void root(int node, int prev, int id){
    m[node] = id;
    for(auto e :adj[node]){
        if(e == prev) continue;
        root(e, node, id^(1<<(s[mp(e, node)])));
    }
    
}

void solve(){
    cin >> N;
    loop(i, N){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        s[mp(a, b)]=i;
        s[mp(b, a)]=i;
    }
    cout << (1<<(N-1)) << endl;
    for(int i = 0; i<(1<<N);i++){
        if(__builtin_popcount(i)%2==0) {
            root(0, 0, i);
            FOR(j, 0, N) cout << m[j] << " ";
            cout << endl;
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    solve();   
}
