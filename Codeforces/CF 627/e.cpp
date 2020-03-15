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
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 2100


ll n, h, l, r;
ll memo[limit][limit];
vector<ll> s;


ll dp(ll i, ll t){ 
    if(memo[i][t]!=-1) return memo[i][t];
    if(i==n) return memo[i][t] = 0;
    ll delay =s[i];
    ll d1, d2;
    d1 = 0;
    d2 = 0;
    if((t+delay)%h >= l and (t+delay)%h <= r) d1 = 1;
    if((t+delay-1)%h >= l and (t+delay-1)%h <= r) d2 = 1;
    return memo[i][t] = max(
        dp(i+1, (t+delay)%h) + d1,
        dp(i+1, (t+delay-1)%h) +d2);
}



int main(){
    memset(memo, -1, sizeof memo);
    cin >> n >> h >> l >> r;
    loop(i, n){
        ll temp;
        cin >> temp;
        s.pb(temp);
    }
    cout << dp(0,0) << endl;
}