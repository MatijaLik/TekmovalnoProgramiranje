/**
 * Author: MatijaL
 * Time: 2021-06-30 01:20:19
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
int main(){
    int d[1000500];
    memset(d, 0, sizeof d);
    ios::sync_with_stdio(0);
    cin.tie(0);
    FOR(i, 2, 1000000){
        if(d[i] == 0){
            d[i] = i;
            for(ll j = i*i; j < 1000200; j += i) d[j] = i;
        }
    }

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans= 1;

        unordered_map<int, int> m;
        while(n != 1){
         
            m[d[n]]++;
            n = n / d[n];
        }
        for(auto e : m) ans *= e.sc + 1;
        cout << ans << endl;
    }
}
