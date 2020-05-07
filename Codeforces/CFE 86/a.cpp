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
    int t;
    cin >> t;
    loop(i, t){
        ll x, y;
        ll a, b;
        cin >> x >> y;
        cin >> a >> b;
        ll res;
        if(y >= 0 and x >= 0){
            res = a*abs(x-y);
            res += min(2*a, b)*min(x, y);
        }else if(x < 0 and y < 0){
            res = a*abs(x-y);
            res += min(2*a, b)*max(x, y)*(-1);
        }else{
            res = a*abs(x) + a*abs(b);
        }
        cout << res << endl;
    }
}