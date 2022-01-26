/**
 * Author: MatijaL
 * Time: 2022-01-22 15:35:03
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
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;


const int MOD = 1000000007;
const int Nlimit = 2010;

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

int inv(int x)
{
	return binpow(x, MOD - 2);
}



void solve(){
    int N, M, K;
    cin >> N >> M >> K;
    
    ll DP[Nlimit][Nlimit];
    FOR(n, 0, Nlimit) DP[n][0] = 0;
    FOR(n, 1, N){
        FOR(m, 1, M){
            if(m > n) continue;
            if(m==n) DP[n][m] = add(K,DP[n-1][m-1]);
            else{
                DP[n][m] = mul(add(DP[n-1][m-1],DP[n-1][m]), inv(2));
            }
        }
    }
    cout << DP[N][M] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
