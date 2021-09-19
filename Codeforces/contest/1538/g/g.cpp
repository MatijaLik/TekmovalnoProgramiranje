/**
 * Author: MatijaL
 * Time: 2021-06-28 13:27:14
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
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

void solve(){
    double x, y, a, b;
    cin >> x >> y >> a >> b;

    //a mora biti < b
    if(a > b) swap(a, b);

    

    double xInt = (a*x - b*y) / (a*a - b*b);
    double yInt = (x - xInt*a)/b;

    if(a == b or xInt < 0 or yInt < 0){
        printf("%lld\n",(ll)floor(min(x, y)/min(a, b)));
        return;
    }

    //printf("x %.3lf | y %.3lf\n", xInt, yInt);

    ll ans1 = floor(xInt) + floor((x - floor(xInt)*a)/b);
    ll ans2 = ceil(xInt) + floor((y - ceil(xInt)*b)/a);
    ll ans3 = min(floor(x/b), floor(y/a));
    ll ans4 = min(floor(x/a), floor(y/b));
    printf("%lld\n", max(max(ans1, ans2), max(ans3, ans4)));
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
