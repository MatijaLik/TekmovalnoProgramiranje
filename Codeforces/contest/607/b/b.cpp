/**
 * Author: MatijaL
 * Time: 2021-01-11 21:36:22
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
int memo[510][510];
vector<int> s;
int n;
int dp(int l, int r){
    if(memo[l][r] != -1) return memo[l][r];
    if(l >= r) return memo[l][r] = 1;
    

    int best = inf;
    if(s[l] == s[r]) best = dp(l+1, r-1);
    FOR(nl, l+1, r){
        best = min(best, dp(l, nl-1)+dp(nl, r));
    }
   return memo[l][r] = best;
}
void solve(){
    loop(i, 510)loop(j, 510) memo[i][j] = -1;
    cin >> n;
    loop(i, n){
        int temp;
        cin >> temp;
        s.pb(temp);
    }
    cout << dp(0, n-1) << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
