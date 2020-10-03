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
#define inf 1000000000
#define mod 1000000007

const int MOD = 1000000007;
int add(int x, int y)
{
	return (x + y) % MOD;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

void solve(){
    ll ans = 0;
    ll N;

    cin >> N;
    int fact[N+10];
    fact[0] = 1;
	for(int i = 1; i <= N; i++)
		fact[i] = mul(i, fact[i - 1]);

    ans = sub(fact[N], binpow(2, N-1));
    cout << ans << endl;
        
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}