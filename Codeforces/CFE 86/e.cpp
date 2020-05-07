#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define plll pair<pll, ll>
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
#define mod 998244353
#define debug(x) cout << "# " << x << endl

#define nlimit 200100
map<pll, ll> combMemo;
set<pll> combMemoS;

ll comb(ll n, ll k){
    pll p = mp(n, k);
    if(combMemoS.count(p)) return combMemo[p];
    combMemoS.insert(p);
    if(n==k) return combMemo[p] = 1;
    if(n == 0) return combMemo[p] = 0;
    return combMemo[p] = (comb(n-1, k) + comb(n-1, k-1))%mod;
}

ll N, K;

ll g(ll n){return n-1;}



map<plll, ll> memo;
set<plll> memoS;

ll dp(ll pos, ll sum, ll clust){
    plll p = mp(mp(pos, sum), clust);
    if(memoS.count(p)) return memo[p];
    memoS.insert(p);

    if(pos == N){
        //sprazni clust
    } return memo[p] = 0;
    if(sum == 0) return memo[p] = 0;

    ll ans = 0;
    FOR(i, 2, )


    return memo[p] = ans;
}

int main(){


}