#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define plll pair<ll,pair<ll, ll>>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 10000000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 500010

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a%b);
}


ll N, M, D;
vector<ll> a;

map<pair<pll, pll>, ll> memo;
set<pair<pll, pll>> memoS;

ll dp(ll i, ll cur, ll m, ll g){
    //cout << "dp " << i << " "  << cur << " " << m << " " << g << endl;
    pair<pll,pll> p = mp(mp(i, cur),mp(m ,g));
    if(memoS.count(p)) return memo[p];
    memoS.insert(p);
    if(m == -1) return memo[p] = -inf;
    if(M-i+cur < D) return memo[p] = -inf;
    if(i == M) return memo[p] = g;
    if(cur < D){
        memo[p] = dp(i+1, cur+1, m, gcd(g, a[i])); // dodaj
    }
    else{
        ll ans = max(
            g + dp(i+1, 1, m-1, a[i]), //zacni na novo
            dp(i+1, cur+1, m, gcd(g, a[i])) // dodaj
        );
        //cout << "dp " << i << " "  << cur << " " << m << " " << g << " ans is: " << ans << endl;
        return memo[p] = ans;
    }
}

int main(){
    cin >> N >> M >> D;
    loop(q, N){
        ll t;
        cin >> t;
        loop(i, t){
            ll temp;
            cin >> temp;
            a.pb(temp);
        }
    }
    //reverse(all(a));
    /*
    cout << "####" << endl;
    */
    /*
    cout << "////" << endl;
    loop(i, M){
        cout << a[i] << endl;
    }*/
    //cout << "////" << endl;
    cout << dp(1, 1, N-1, a[0]) << endl;
    return 0;

}