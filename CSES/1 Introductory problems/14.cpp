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


ll N;
map<pll, ll> memo;
set<pll> visited;
vector<int> v;

ll cs[30];

ll dp(ll dif, ll n, ll depth){

    /*
    loop(i, depth) cout << "|  ";
    printf("dp %lld %lld\n", dif, n);
    */

    pll p = mp(dif, n);
    if(visited.count(p)) return memo[p];
    visited.insert(p);

    if(n == N) return memo[p] = abs(dif);
    ll el = v[n];

    if(abs(dif) > cs[n]) return memo[p] = min(abs(dif - cs[n]), abs(dif + cs[n]));

    ll ans = min(
        dp(dif + el, n+1, depth + 1),
        dp(dif - el, n+1, depth + 1)
    );

    /*
    loop(i, depth) cout << "|  ";
    printf("(%lld)\n", ans);
    */
    return memo[p] = ans;

}


int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N;
    loop(i, N){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(all(v));
    reverse(all(v));

    
    cs[N] = 0;
    for(int i = N-1; i >= 0; i--)cs[i] = v[i] + cs[i+1];

    /*
    printf("cs\n");
    FOR(i, 0, 5) cout << cs[i] << " ";
    cout << endl;
    */
    
    cout << dp(0, 0, 0) << endl;

}