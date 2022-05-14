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





void solve(){
    int n;
    cin >> n;

    int memo[10000009];
    memset(memo, 0, sizeof memo);
    memo[0]=1;
    FOR(i, 0, n){
        FOR(x, 1, 6){
            memo[i+x] += memo[i];
            memo[i+x] %= mod;
        }
    }
    
    cout << memo[n] << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();   
}