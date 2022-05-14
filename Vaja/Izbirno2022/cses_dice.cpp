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


int memo[10000005];

int dp(int n){
    if(n==0) return 1;
    if(memo[n]) return memo[n];
    int ans = 0;
    FOR(i, 1, 6){
        if(n-i>=0)
            ans = (ans+dp(n-i))%mod;
    }
    return memo[n] = ans;
}


void solve(){
    int n;
    cin >> n;

    cout << dp(n) << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();   
}