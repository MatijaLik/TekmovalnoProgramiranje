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

ll ans;

bool rows[8];
bool diag1[18];
bool diag2[18];

bool grid[8][8];

void change(int x, int y, bool state){
    rows[y] = state;
    diag1[x+y] = state;
    diag2[x-y+8] = state;
}

void f(int x, int depth){
    if(x == 8) ans++;

    //probaj vseh 8 vrstic
    loop(y, 8){
        if(!grid[x][y]) continue;
        if(rows[y]) continue;
        if(diag1[x+y]) continue;
        if(diag2[x-y+8]) continue;

        change(x, y, true);
        /*
        loop(i, depth) cout << "| ";
        printf("%d\n", y);
        */
        f(x+1, depth+1);
        change(x, y, false);
    }

}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    loop(y, 8)loop(x, 8){
        char c;
        cin >> c;
        if(c == '.') grid[x][y] = 1;
        else grid[x][y] = 0;
    }

    f(0, 0);
    cout << ans << endl;
}