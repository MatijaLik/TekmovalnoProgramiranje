/**
 * Author: MatijaL
 * Time: 2020-11-08 18:32:40
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
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> a = {0,0};
    vector<int> ab = {0, 0, 0};
    vector<int> abc = {0, 0, 0, 0};

    int k = 0;

    for(auto c : s){
        int shift = c == '?' ? 1 : 0;
        bool q = c == '?';
        if(q) k++;
        if(c == 'c' or q){
            loop(i, 3) abc[i+shift] = add(abc[i+shift], ab[i]);
        }
        if(c == 'b' or q){
            loop(i, 2) ab[i+shift] = add(ab[i+shift], a[i]);
        }
        if(c == 'a' or q){
            a[shift] = add(a[shift], 1);
        }
    }

    ll ans = 0;
    ans = add(ans, mul(abc[0], binpow(3, k)));
    ans = add(ans, mul(abc[1], binpow(3, k-1)));
    ans = add(ans, mul(abc[2], binpow(3, k-2)));
    ans = add(ans, mul(abc[3], binpow(3, k-3)));

    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
