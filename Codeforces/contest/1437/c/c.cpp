/**
 * Author: MatijaL
 * Time: 2020-11-04 15:03:21
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

vector<int> v;
int N;



void solve(){
    cin >> N;
    v.clear();
    loop(i, N){
        int temp;
        cin >> temp;
        v.pb(temp);
    }

    sort(all(v));
    //for(auto e : v) cout << e << " ";
    //cout << endl;

    int dp[N+1][400];
    loop(i, N+1)loop(j, 400) dp[i][j] = inf;
    loop(i, 400) dp[0][i] = 0;
    FOR(pos, 1, N){
        FOR(T, 1, 399){
            dp[pos][T] = min(dp[pos][T-1], dp[pos-1][T-1]+(int)abs(T - v[pos-1]));
        }
    }

    cout << dp[N][355] << endl;

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
