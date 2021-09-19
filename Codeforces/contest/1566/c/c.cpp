/**
 * Author: MatijaL
 * Time: 2021-09-12 16:35:12
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

string a, b;

    int n;
int dp[200000][3];
int DP(int pos, int mex){
    if(pos == n) return mex;
    if(dp[pos][mex] != -1) return dp[pos][mex];
    int mx = 0;
    int A = a[pos] - '0';
    int B = b[pos] - '0';
    int ntop = max(A,B);
    int nmex;
    if(A!=B) nmex = 2;
    else nmex = 1 - ntop;

    mx = max(mx,mex+ DP(pos+1, nmex));

    //zdruzimo
    int propMex;
    if(pos == 0 or (nmex == mex and mex < 2)) propMex = mex;
    else propMex = 2;
    mx = max(mx, DP(pos+1, max(nmex, propMex)));

    //printf("dp %d %d ---> %d\n", pos, mex, mx);
    return dp[pos][mex] = mx;

}

void solve(){
    cin >> n;
    cin >> a >> b;
    loop(i, n) loop(j, 3) dp[i][j] = -1;
    cout << DP(0, 0) << endl;
   
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
