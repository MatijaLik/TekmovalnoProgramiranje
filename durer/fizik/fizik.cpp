/**
 * Author: MatijaL
 * Time: 2020-11-25 19:44:26
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
    vector<long double> m(1000);
    vector<long double> v(1000);


    m[0] = 1.0;
    v[0] = 10.0;

    FOR(i, 1, 150) m[i] = 0.7*m[i-1];

    FOR(i, 1, 150){
        v[i] = v[i-1] * (2*m[i-1])/(m[i-1]+m[i]);
        printf("%d %020.3Lf  %0.15Lf\n", i+1, v[i], m[i]);
    }


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
