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
#define mod 998244353
#define debug(x) cout << "# " << x << endl


#define limit 500100

ll factArr[limit];

ll fact(ll a){
    return factArr[a];
}

ll multiply(ll a, ll b){
    return (a*b)%mod;
}

ll fastPow(ll base, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp % 2) res = multiply(res, base);
        exp /= 2;
        base = multiply(base, base);
    }
    return res;
}

ll inv(ll a){
    return fastPow(a, mod-2);
}

ll comb(ll n, ll k){
    return multiply( fact(n)  , multiply(inv(fact(n-k)), inv(fact(k))));
}

int main(){
    ll N, K;
    cin >> N >> K;

    factArr[0] = 1;
    factArr[1] = 1;
    FOR(i, 2, limit){
        factArr[i] = multiply(factArr[i-1], i);
    }


    ll res = 0;
    for(int i = 1; i <= N; i++){
        ll m = floor(N/i) - 1;
        if(m >= K-1) res = (res+ comb(m, K-1)) % mod;
        else break;
    }

    cout << res << endl;
}