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
#include <math.h>
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

map<pll, ll> memo; 

int gcd(int a, int b)
{
    if(memo[mp(a,b)]!=0) return memo[mp(a,b)];
    if(memo[mp(b,a)]!=0) return memo[mp(b,a)];
    if(b == 0){
        return memo[mp(a,b)] = a;
    }else{
        return memo[mp(a,b)] = gcd(b, a%b);
    }
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}



#define limit 1000000010

int main(){
    ll t;
    cin >> t;
    loop(q, t){
        ll x;
        cin >> x;
        cout << 1 << " " << x-1 << endl;
    }
    return 0;
}