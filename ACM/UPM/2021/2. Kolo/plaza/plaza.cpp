/**
 * Author: MatijaL
 * Time: 2021-05-06 16:08:44
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


#define limit 200

int color[limit];
vector<int> sosed[limit];

void dfs(int cur, int c){
    color[cur] = c;
    for(auto e : sosed[cur]){
        if(color[e] == 0){
            if(c == 1) dfs(e, 2);
            else dfs(e, 1);
        }
    }
}

void solve(){

    int n, m;
    cin >> n >> m;
    loop(i, m){
        int a, b;
        cin >> a >> b;
        sosed[a].pb(b);
        sosed[b].pb(a);
    }


    FOR(i, 1, n){
        if(color[i]==0) dfs(i, 1);
    }

    FOR(i, 1, n) if(color[i] == 1) cout << i << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
