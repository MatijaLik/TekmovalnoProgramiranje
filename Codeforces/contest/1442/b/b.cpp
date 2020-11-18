/**
 * Author: MatijaL
 * Time: 2020-11-03 17:38:36
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

void solve(){
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    vector<int> a(n), b(k);
    loop(i, n){
        cin >> a[i];
        m[a[i]] = i;
    }
    loop(i, k) cin >> b[i];
    vector<int> v(n, 0);
    int cnt = 1;
    for(auto e : b){
        v[m[e]] = cnt++;
    }


    
    ll ans = 1;
    loop(i, n){
        int e = v[i];
        if(e == 0) continue;
        ll opt = 0;
        if(i != 0) if(v[i-1] < e) opt++;
        if(i != n-1) if(v[i+1] < e) opt++;

        ans = mul(ans, opt);
    }
    
    cout << ans << endl;

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
