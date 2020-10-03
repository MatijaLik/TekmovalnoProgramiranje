/**
 * Author: MatijaL
 * Time: 2020-08-25 16:35:02
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
#define inf 1000000000
#define mod 1000000007
#define limit 3010
int a[limit];
 
int pref[limit][limit];
int suff[limit][limit];
 
void solve(){
    int n;
    cin >> n;
    loop(i, n)cin >> a[i+1];
 

    FOR(num, 1, 3000){
        int pre = 0;
        int suf = 0;
        pref[num][0] = 0;
        suff[num][n+1] = 0;
        FOR(index, 1, n){
            ll val = a[index];
            if(val == num) pre++;
            pref[num][index] = pre;
        }
        for(int index = n; index>=1; index--){
            ll val = a[index];
            if(val == num) suf++;
            suff[num][index] = suf;
        }
    }
    ll ans = 0;
    FOR(j, 1, limit){
        FOR(k, j+1, limit){
            ll val1 = a[k];
            ll val2 = a[j];
            ans += pref[val1][j-1]*suff[val2][k+1];
        }
    }
    cout << ans << endl;
}
 
int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
