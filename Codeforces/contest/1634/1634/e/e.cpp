/**
 * Author: MatijaL
 * Time: 2022-02-06 15:35:02
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

void solve(){
    int M;
    cin >> M;
    char g[M][N];
    memset(g, 0, sizeof g);
    
    
    map<int,multiset<int>> whereNumber;
    multiset<pll> arrays[M];
    
    loop(i, M){
        int n;
        cin >> n;
        loop(j, n){
            int t;
            cin >> t;
            arrays[j].insert(t);
            whereNumber[t].insert(j);
        }
    }
    
    int curArr = 0;
    while(curArr<M){
        while(!arrays[curArr].empty()){
            int cr = curArr;
            
            auto t = arrays[cr].begin();
            pll p1 = *t;
            arrays[cr].erase(t);

            int start = p.fs;
            int id_1 = p.sc;
            g[cr][id_1] = 'L';
            
            int cur=-1;
            while(cur!=start){
                auto tn = arrays[cr].lower_bound(mp(start, 0));
            }
            
        }
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
