#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
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
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

ll memo[32][32];

ll dp(ll n, ll k){
    if(n == 0 or k == 0) return memo[n][k] = 1;
    if(n == k) return memo[n][k] = 1;
    if(memo[n][k]!= 0) return memo[n][k];

    return memo[n][k] = dp(n-1, k) + dp(n-1, k-1);
}

int main(){
    int n;
    cin >> n;
    //int k;
    //cin >> k;
    cout << dp(2*n,n)/(n+1)<< endl;
    return 0;
}