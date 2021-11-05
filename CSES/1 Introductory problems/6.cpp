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


ll solve(){
    ll x, y;
    cin >> y >> x;
    if(x >= y){
        ll start;
        if(x % 2) start = x*x;
        else start = (x-1)*(x-1) + 1;

        if(x % 2) return (start - y + 1);
        else return (start + y - 1);
    }else{
        ll start;
        if(y % 2 == 0) start = y*y;
        else start = (y-1)*(y-1) + 1;

        if(y % 2 == 0) return (start - x + 1);
        else return (start + x - 1);
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) cout << solve() << endl;   
}