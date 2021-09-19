/**
 * Author: MatijaL
 * Time: 2021-03-27 11:45:09
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

#define DEBUG 0

void solve(){
    int D, k;
    cin >> k >> D;
    if(D == 0){
        cout << ceil(sqrt(4*k)) << endl;
        return;
    }

    vector<pll> d;
    set<ll> x;
    unordered_map<ll, ll> amnt;
    d.pb(mp(0,0));
    loop(i, D){
        int a, b;
        cin >> a >> b;
        x.insert(a);
        amnt[a] = max(amnt[a], (ll)b);
    }

    for(auto e :x) d.pb(mp(e, amnt[e]));
    

    const int dayLimit = 10300;
    const int powerLimit = 1000;

    ll dp[dayLimit][powerLimit];
    FOR(dan, 0, dayLimit-1)
        FOR(p, 0, powerLimit-1) dp[dan][p] = -inf;

    dp[0][0] = 0;
    
    FOR(dan, 1, dayLimit-1){
        FOR(p, 0, powerLimit-1){
            //nadgradi
            //smo prejsnji dan dosegli kvoto?
            if(p != 0 and dp[dan-1][p-1] >= amnt[dan-1]) dp[dan][p] = max(dp[dan][p], dp[dan-1][p-1]);

            //delaj
            //smo prejsnji dan dosegli kvoto?
            if(dp[dan-1][p] >= amnt[dan-1]) dp[dan][p] = max(dp[dan][p], dp[dan-1][p] + p);

            if(DEBUG) printf("dp day %lld power %lld -> %lld\n", dan, p, dp[dan][p]);
            if(dp[dan][p] >= k){
                cout << dan << endl;
                return;
            }
        }
    }
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=  1;
    while(t--) solve();   
}
