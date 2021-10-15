/**
 * Author: MatijaL
 * Time: 2021-09-28 16:35:02
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
    int n, m, k;
    cin >> n >> m >> k;
    bool grid[n][m];
    loop(j, n){
        string s;
        cin >> s;
        loop(i, m){
            if(s[i] == '*') grid[j][i] = 1;
            else grid[j][i] = 0;
        }
    }
    
    bool status[n][m];
    memset(status, 0, sizeof status);
    for(int j = n-1; j >= 0; j--){
        for(int i = 0; i < m; i++){
            int ach = 1;
            if(grid[j][i]){
                vector<pll> q;
                while(j - ach >= 0 and i + ach < m and i - ach >= 0
                        and grid[j - ach][i + ach]and 
                        grid[j - ach][i - ach]){
                    q.pb(mp(j-ach, i+ach));
                    q.pb(mp(j-ach, i-ach));
                    ach++;
                }
                if(!status[j][i] and ach-1 < k){
                    cout << "NO" << endl;
                    return;
                }
                if(ach - 1>=k){
                    for(auto e : q) status[e.fs][e.sc] = true;
                }
            }
        }
    }
    cout << "YES" << endl;

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
