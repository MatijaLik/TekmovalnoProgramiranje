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
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    ll cs[n+1];
    cs[0] = 0;
    map<ll, ll> s;
    //s.reserve(200100);
    s[0]++;
    ll ans = 0;
    loop(i, n){
        cs[i+1] = cs[i] + v[i];
        ll r = cs[i+1]%n;
        r = (r+n)%n;
        ll sum = r;
        ans += s[sum];
        s[r]++;
    }
    cout << ans << endl;
}
