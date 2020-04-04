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
#define inf INT_MAX
#define mod 998244353
#define debug(x) cout << "# " << x << endl;

#define limit 3

int main(){
    ll N;
    cin >> N;
    vector<ll> ans;
    vector<ll> ten;
    ll x = 1;
    ten.pb(x);
    loop(i, N){
        x *= 10;
        x = x%mod;
        ten.pb(x);
    }
    for(ll i = N; i >= 1; i--){
        if(i==N) {ans.pb(10);continue;}
        ll r = N-i;//size
        ll out = 2*ten[N-i]*9;
        out += (N-1-i)*ten[N-i-1]*81;
        out %= mod;
        ans.pb(out);
    }
    reverse(all(ans));
    for(auto h : ans){
        cout << h << endl;
    }

}