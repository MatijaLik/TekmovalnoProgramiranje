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


vector<int> a;

int n;
int k;

map<pii, int> memo;
set<pii> memoS;


int dp(int pos, int amnt){
    pii p = mp(pos, amnt);
    if(memoS.count(p)) return memo[p];
    else memoS.insert(p);

    if(amnt == 0) return memo[p] =  0;
    if(n - pos < amnt) return memo[p] = inf;//moremo vzeti vec, kot je elementov
    if(pos >= n) return memo[p] =  0;
    

    //vzemi prvega
    int best = inf;
    FOR(i, pos, n-1){
        int prop = max(
            dp(i+2, amnt-1),
            a[i]
        );
        best = min(best, prop);
    }

    return memo[p] = best;
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> n >> k;

    loop(i, n){
        int temp;
        cin >> temp;
        a.pb(temp);
    }

    cout << min(
        dp(0, ceil((double)k/2.0)),
        dp(1, floor((double)k/2.0))
        )
    << endl;

}