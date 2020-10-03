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
    int n, m, x , y;
    cin >> n >> m >> x >> y;

    char grid[n][m];
    loop(i, n)loop(j, m) cin >> grid[i][j];


    int smol = 0;
    int big = 0;

    loop(i, n){
        loop(j, m){
            char c = grid[i][j];
            if(c == '.'){
                smol++;
                if( j > 0  and grid[i][j-1] == '.'){
                    smol -= 2;
                    big++;
                    grid[i][j] = '*';
                }
            }
        }
    }

    //rintf("big %d and smol %d\n", big, smol);

    if(2*x < y) cout << (smol+(big*2))*x << endl;
    else cout << smol*x + big*y << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}   