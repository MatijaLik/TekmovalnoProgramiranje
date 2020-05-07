#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
#define mod 1000000000
#define debug(x) cout << "# " << x << endl

#define start 1e18
#define nlimit 400

ld memo[nlimit][nlimit];
int w, h; 

ld dp(int x, int y){
    if(x == 0 or y == 0) return memo[x][y] = 0;
    if(memo[x][y]!= -1) return memo[x][y];
    if(x == w and y == h) return memo[x][y] = dp(x-1, y) + dp(x, y-1);
    if(x == w) return  memo[x][y] = dp(x-1, y)/2 + dp(x, y-1);
    if(y == h) return  memo[x][y] = dp(x-1, y) + dp(x, y-1)/2;
    return memo[x][y] = (dp(x-1, y) + dp(x, y-1))/2;
}


void solve(int cs){
    loop(i, nlimit)loop(j, nlimit) memo[i][j] = -1;
    memo[1][1] = start;

    ld ans = 0;
    int l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    


    //prvo gremo zgoraj (l, u) (r, u)
    FOR(i, l, r){
        ans += dp(i, u);
        if(u == 1) break;
        if(i != l) ans -= dp(i-1, u)/2;
    }
    //od (l, u) do (l, d)
    FOR(i, u+1, d){
        if(l == 1) break;
        else{
            ans += dp(l, i);
            ans -= dp(l, i-1)/2; 
        } 
    }

    printf("Case #%d: ", cs);
    cout << 1-(ans/start) << endl;
}


int main(){
    
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}