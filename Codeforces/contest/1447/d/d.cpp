/**
 * Author: MatijaL
 * Time: 2020-11-15 15:35:01
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

#define limit 5010

int N, M;
string a, b;
ll memo1[limit][limit];
ll memo2[limit][limit];

ll ans = 0;

ll dp1(int n, int m){
    if(n == 0 or m == 0) return 0;
    ll res;
    if(a[n-1] == b[m-1]){
        res = 1 + dp1(n-1, m-1);
    }else{
        res = max(dp1(n, m-1), dp1(n-1, m));
    }

    memo1[n][m] = res;
    ans = max(4*res - n - m, ans);
    return res;
}

ll dp2(int n, int m){
    if(n == N or m == M) return 0;
    ll res;
    if(a[n] == b[m]){
        res = 1 + dp1(n+1, m+1);
    }else{
        res = max(dp1(n, m+1), dp1(n+1, m));
    }

    memo2[n][m] = res;
    ans = max(4*res - n - m, ans);
    return res;
}

void solve(){
    cin >> N >> M;
    loop(i, limit) loop(j, limit){
        memo1[i][j] = -1;
        memo2[i][j] = -1;
    }
    cin >> a >> b;
    cout << dp1(N, M) << endl;
    cout << dp2(0, 0) << endl;

    cout << ans << endl;
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
