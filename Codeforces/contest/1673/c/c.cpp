/**
 * Author: MatijaL
 * Time: 2022-04-30 16:53:41
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


vector<int> pal;
vector<int> dp(41000, 0);

void precalc(){
    FOR(i, 1, 40000){
        string s;
        int j = i;
        while(j>0){
            s += (j%10)+'0';
            j /= 10;
        }
        string r = s;
        reverse(all(r));
        if(s==r) pal.pb(i);
    }
}

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    precalc();
    //print(pal);
    //cout << pal.size() << endl;
    
    dp[0] = 1;
    for(auto p : pal){
        FOR(i, 0, 40000){
            if(i+p<=40000){
                dp[i+p] += dp[i];
                dp[i+p] %= mod;
            }
        }
    }
    FOR(i, 1, 5){
       // cout << dp[i] << endl;
    }
    
    
    int t;
    cin >> t;
    while(t--) solve();   
}
