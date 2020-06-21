#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl


void solve(){
    int n;
    cin >> n;
    bool grid[n+1][n+1];
    loop(i, n){
        string s;
        cin >> s;
        loop(j, n){
            grid[i][j] = s[j] == '1';
        }
    }
    //naredi rob
    loop(i, n){
        //spodi
        grid[n][i] = 1;
        
        //desno
        grid[i][n] = 1;
    }
    //preisci
    loop(i, n){
        loop(j, n){
            bool c = grid[i][j];
            if(!c) continue;
            if(grid[i+1][j] == false and grid[i][j+1] == false){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}