/**
 * Author: MatijaL
 * Time: 2021-02-17 15:54:54
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
    int n;
    cin >> n;
    int adj[n][n];
    loop(i, n)loop(j, n){
        cin >> adj[i][j];
    }


    int k;
    cin >> k;
    while(k--){
        int a,b,c;
       
        cin >> a >> b >> c; a--;
        b--;
        if(adj[a][b] > c){
            adj[a][b] = c;
            adj[b][a] = c;
        }


        loop(i, n)loop(j, n){
            if(i == j) continue;
            if(adj[i][j] > adj[i][a] + c + adj[b][j]){
                adj[i][j] = adj[i][a] + c + adj[b][j];
                adj[j][i] = adj[i][a] + c + adj[b][j];
            }
        }
    

        ll cnt = 0;
        loop(i, n)loop(j, n){
            if(i >= j) continue;
            cnt += adj[i][j];
        }
        cout << cnt << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
