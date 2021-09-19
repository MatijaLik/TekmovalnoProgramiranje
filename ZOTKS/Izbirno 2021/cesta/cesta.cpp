/**
 * Author: MatijaL
 * Time: 2021-05-27 17:21:22
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

const double EPS = 1e-4;

#define DEBUG 0
 

void solve(){
   

    double L, N;
    vector<pair<double, double>> ludi; //<zacetek poti, konec poti>

    int dp[510];


    cin >> L >> N;
    loop(i, N){
        double v, t;
        cin >> t >> v;
        double tEnd = L/v + t;
        tEnd = min(tEnd, (double)inf);  
        ludi.pb(mp(t, tEnd));
    }

    sort(all(ludi));
    if(DEBUG){
        for(auto e : ludi) printf("%.1lf %.1lf\n", e.fs, e.sc);
    }

    loop(i, N) dp[i] = 1;
    for(int i = N-1; i >= 0; i--){
        FOR(j, i+1, N-1){
            if(ludi[i].sc > ludi[j].sc or ludi[i].sc == inf) 
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }




    int ans = 1;
    loop(i, N){
        //printf("%d\n", dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
