#include <bits/stdc++.h>
#pragma optimize ("Ofast")
#pragma GCC target("popcnt")
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
 
#define limit 100200
#define DEBUG 0
const ll INF = inf*1LL*inf;

//Beautiful Subgrids


void solve(){
    int n;
    cin >> n;
    bitset<3000> v[3000];
    loop(i, n){
        cin >> v[i];
    }

    ll ans = 0;
    loop(i, 3000){
        FOR(j, i+1, 2999){
            ll bCnt =  (v[i]&v[j]).count();
            ans += (bCnt*(bCnt-1));
        }
    }

    cout << ans/2 << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();


    return 0;
}