/**
 * Author: MatijaL
 * Time: 2021-03-27 11:08:17
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

#define DEBUG 0

void solve(){
    ll n, m;
    cin >> n >> m;
    map<pll, int> adj;
    if(DEBUG) printf("%d\n", adj[mp(0,0)]);


    vector<int> sosedi[200000];
    vector<pll> v;
    loop(i, m){
        int a, b, p;
        cin >> a >> b >> p;
        if(p == 0) p = -1;
        
        adj[mp(a, b)] = p;
        adj[mp(b, a)] = p;
        v.pb(mp(a, b));
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    for(auto e : v){
        int a = e.fs;
        int b = e.sc;

        for(auto c : sosedi[a]){
            if(c == b) continue;
            if(DEBUG) printf("%d %d %d\n",a , b, c);
            int prod = adj[mp(a, b)] * adj[mp(a, c)] * adj[mp(b, c)];
            if(prod != 1){
                cout << "NE" << endl;
                return;
            }
        }
        for(auto c : sosedi[b]){
            if(c == a) continue;
            if(DEBUG) printf("%d %d %d\n",a , b, c);
            int prod = adj[mp(a, b)] * adj[mp(a, c)] * adj[mp(b, c)];
            if(prod != 1){
                cout << "NE" << endl;
                return;
            }
        }
        
    }

    cout << "DA" << endl;

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
