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
#include <algorithm>
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

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    loop(q, 2*k){
        ll a, b;
        cin >> a >> b;
    }
    string ans;
    //damo gor levo
    loop(i, n-1) ans += "U";
    loop(i, m-1) ans += "L";



    int p = 1;
    loop(i, n){
        if(p)loop(i, m-1) ans += "R";
        else loop(i, m-1) ans += "L";
        ans += "D";
        p = 1-p;
    }
    cout << ans.length() << endl;
    cout << ans << endl;
}
