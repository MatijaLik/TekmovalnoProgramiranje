/**
 * Author: MatijaL
 * Time: 2021-09-12 16:35:12
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

vector<int> sosedi[200000];
int listi = 0;
set<int> buds;

bool dfs(int node, int prev){
    int ss = 0;
    bool bud = true;
    for(auto e : sosedi[node]){
        if(e != prev){
            ss++;
            bool ans = dfs(e, node);
            bud = bud and ans;
        }
    }
    if(bud) buds.insert(node);
    if(ss == 0) listi++;
    if(ss == 0) return true;
    else return false;
}
void solve(){
    int n;
    cin >> n;
    loop(i, n+1) sosedi[i].clear();
    listi = 0;
    buds.clear();
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    dfs(1, 1);
    //to root
    int budsAtRoot = 0;
    for(auto e : sosedi[1]){

        if(buds.count(e)) budsAtRoot++;
    }
    if(sosedi[1].size() == budsAtRoot) budsAtRoot--;
    printf("%d %d\n", listi, budsAtRoot);
    cout << listi - budsAtRoot << endl;
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
