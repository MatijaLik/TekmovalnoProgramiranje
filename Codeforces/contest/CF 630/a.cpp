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
#define debug(x) cout << "# " << x << endl;

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll a, b, c,d;
        cin >> a >> b >> c >> d;

        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        ll dx = abs(a-b);
        ll dy = abs(c-d);


        ll sl = x - x1;
        ll sr = x2 - x;
        ll su = y2 - y;
        ll sd = y - y1;

        bool gucci = 1;

        if(x1 == x2 and (a > 0 or  b > 0)) gucci = 0;
        else{
            if(a > b){
                if(dx > sl) gucci = 0;
            }else{
                if(dx > sr) gucci = 0;
            }
        }
        if(y1 == y2 and (c > 0 or d > 0)) gucci = 0;
        else{
            if(c > d){
                if(dy > sd) gucci = 0;
            }else{
                if(dy > su) gucci = 0;
            }
        }
        if(gucci) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}