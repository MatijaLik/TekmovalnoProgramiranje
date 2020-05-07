#include <bits/stdc++.h>
#include <unistd.h>
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


map<pll, pair<string, bool>> memo;
set<pll> memoS;

pair<string, int> dp(ll x, ll y){
    if(memo.count(mp(x, y)))return memo[mp(x, y)]; 
    memoS.insert(mp(x, y));
    if(x==0 and y==0) return memo[mp(x, y)] = mp("", 1);
    if(x%2 == y%2) return memo[mp(x, y)] = mp("", 0);
    if(x%2 != 0){
        if(dp((x-1)/2, y/2).sc) return memo[mp(x, y)] = mp("E"+dp((x-1)/2, y/2).fs, 1);
        if(dp((x+1)/2, y/2).sc) return memo[mp(x, y)] = mp("W"+dp((x+1)/2, y/2).fs, 1);
        
    }else{
        if(dp(x/2, (y-1)/2).sc) return memo[mp(x, y)] = mp("N"+dp(x/2, (y-1)/2).fs, 1);
        if(dp(x/2, (y+1)/2).sc) return memo[mp(x, y)] = mp("S"+dp(x/2, (y+1)/2).fs, 1);
        
    }
    return memo[mp(x, y)] = mp("",0);
}


void solve(){

    ll x;
    ll y;
    cin >> x >> y;

    if(!dp(abs(x), abs(y)).sc){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    string s = dp(abs(x), abs(y)).fs;
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if(x < 0){
            if(c == 'E') s[i] = 'W';
            else if(c == 'W') s[i] = 'E';
        }
        if(y < 0){
            if(c == 'N') s[i] = 'S';
            else if(c == 'S') s[i] = 'N';
        }
    }
    cout << s << endl;

}


int main(){
    int t;
    cin >> t;
    int i = 1;
    while(t--){
        printf("Case #%d: ", i++);
        solve();
    }
}