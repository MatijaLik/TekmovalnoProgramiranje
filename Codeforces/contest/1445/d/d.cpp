/**
 * Author: MatijaL
 * Time: 2020-11-01 12:05:02
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000005
#define mod 998244353 

const int MOD = 998244353;
int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

#define limit 300100
int fact[limit];


void solve(){
    int N;
    cin >> N;
    vector<ll> a(2*N+1);
    a[0] = 0;

    FOR(i, 1, 2*N) cin >> a[i];
    sort(all(a));

    vector<ll> cumSum(2*N+1);
    cumSum[0] = 0;
    FOR(i, 1, 2*N)cumSum[i] = cumSum[i-1] + a[i];

    ll ans = 0;

    ll prevCost = 0;
    FOR(i, 1, N){
        ll pivot = a[2*N-i+1];
        ll L = i;
        ll R = N;

        printf("%d %d %d\n", pivot, L, R);

        ll sum = cumSum[R]-cumSum[L-1];
        ll cost = (R-L+1)*pivot - sum;

        printf("%d %d\n", sum, cost);

        //ans = add(ans, mul(cost%mod, mul(fact[R-L+1],fact[i])));
        cost %= mod;
        ans = add(ans, mul(cost, 2));
        ans = add(ans, mul(prevCost, 2));
        prevCost = cost;
    }
    cout << ans << endl;
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
	for(int i = 1; i <= limit; i++)
		fact[i] = mul(i, fact[i - 1]);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
