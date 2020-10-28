/**
 * Author: MatijaL
 * Time: 2020-10-04 18:05:01
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
const int MOD = mod;
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


void solve(){
    string s;
    vector<ll> v;
    cin >> s;
    for(auto c : s){
        v.pb((ll) c - '0');
    }

    ll res = 0;

    //first sum
    ll sum = 0;
    ll N = s.length();
    FOR(i, 0, N-2){

        sum = add(sum, v[i]);
        ll exp = N-i-2;
        ll coef = N-i-1;
        //cout << sum << " " << exp << " " << coef << endl;
        res = add(res, mul(mul(coef, sum), binpow(10, exp)));
        //cout << res << endl;
    }
    //cout << res << endl; 
    sum = 0;
    for(int i = N-1; i > 0; i--){
        ll exp = N-i-1;
        int num = mul(v[i], binpow(10, exp));
        ll rem = i;

        ll coef = rem*(rem-1);
        coef /= 2;
        coef += rem;
        coef %= MOD;
        
        //cout << num<< " " << coef << endl;

        res = add(res, mul(coef, num));
       // cout << "#" << res << endl;
    }
    cout << res << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
