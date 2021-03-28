/**
 * Author: MatijaL
 * Time: 2021-03-26 19:18:32
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

int solve(){
    int x, y;
    cin >> x >> y;
    swap(x, y);
    string s = "X";
    string temp;
    cin >> temp;
    s += temp;
    int n = s.length();
    int dp[n+10][2];//0 C 1 J
    dp[0][0] = 0;
    dp[0][1] = 0;
    FOR(i, 1, n){
        char c = s[i];
        //ce bi dali C
        dp[i][0] = min(dp[i-1][0], x + dp[i-1][1]);
        if(c == 'J') dp[i][0] = inf;

        //ce bi dali J
        dp[i][1] = min(dp[i-1][1], y + dp[i-1][0]);
        if(c == 'C') dp[i][1] = inf;
    }

    return min(dp[n][0], dp[n][1]);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    FOR(i, 1, t) printf("Case #%d: %d\n", i, solve()); 
}
