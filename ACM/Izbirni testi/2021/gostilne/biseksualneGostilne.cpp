/**
 * Author: MatijaL
 * Time: 2021-05-22 10:13:04
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
 
#define limit 100200
#define DEBUG 0
const ll INF = inf*1LL*inf;
 
int N, M;
vector<ll> v;
ll cumSum[limit];
 
ll rangeSum(int l, int r){
    if(l > r) return 0;
    return cumSum[r] - cumSum[l-1];
}
 
ll cost(int l, int r){
    int mid = (l+r)/2;
    if((r-l+1) % 2)
        return rangeSum(mid+1, r) - rangeSum(l, mid-1);
    else
        return rangeSum(mid+1, r) - rangeSum(l, mid);
}
 
void precalc(){
    FOR(i, 1, N) cumSum[i] = cumSum[i-1] + v[i];
}
 
void gremoo(){
    ll mini = INF;
    FOR(i, 1, N-1){
        mini = min(
            mini, 
            cost(1, i) + cost(i+1, N)
        );
    }
 
    cout << mini << endl;
}
 
 
void solve(){
    
    cin >> N >> M;
    v.pb(0);//1-indexed 
    loop(i, N){
        ll t;
        cin >> t;
        v.pb(t);
    }
    sort(all(v));
    //print(v);
    precalc();
 
    if(M==2) {
        gremoo();
        return;
    }
 
    ll dp[N+10][M+10];
    memset(dp, 0, sizeof dp);
 
    //FOR(m, 1, M) dp[0][m] = 0;
    //FOR(m, 1, M) dp[1][m] = 0;
    FOR(n, 1, N) dp[N][0] = INF;
 
    FOR(n, 2, N){
        FOR(m, 1, M){
 
            int l = 1;
            int r = n-1;
            int mid;
 
            if(m == 1){
                dp[n][m] = cost(1, n);
                continue;
            }
 
            ll mini = INF;
            FOR(i, 1, n){
                mini = min(
                    mini,
                    cost(i,n) + dp[i-1][m-1]
                );
            }
 
            dp[n][m] = mini;
 
            
            
        }
    }
 
    cout << dp[N][M] << endl;
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}