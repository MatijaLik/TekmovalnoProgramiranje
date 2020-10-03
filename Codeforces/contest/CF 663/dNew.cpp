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

bool compatible(int a, int b, int sz){

    //prvi kvadrat
    int cnt1 = 0;
    cnt1 += (a >> 0 & 1);
    cnt1 += (a >> 1 & 1);
    cnt1 += (b >> 0 & 1);
    cnt1 += (b >> 1 & 1);

    if(sz == 2){
        if(cnt1 % 2) return true;
        return false;
    }

    //drugi kvadrat
    int cnt2 = 0;
    cnt2 += (a >> 1 & 1);
    cnt2 += (a >> 2 & 1);
    cnt2 += (b >> 1 & 1);
    cnt2 += (b >> 2 & 1);

    if(cnt1 % 2 and cnt2 % 2) return true;
    return false;
}


void solve(){
    ll n, m;
    cin >> n >> m;
    
    int grid[n][m];
    loop(i, n){
        string s;
        cin >> s;
        loop(j, m){
            if(s[j]  == '1') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    if(n >= 4){
        cout << -1 << endl;
        return;
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }

    ll dp[m+10][1 << n];

    //base states
    loop(i, 1 << n){
        dp[0][i] = 0;

        //dodaj cost
        loop(j, n)
            dp[0][i] += (grid[j][0])^(i >> j & 1);
        //printf("state %lld => cost %lld\n", i, dp[0][i]);
    }

    //idemo dalje
    FOR(k, 1, m-1){
        //printf("index %lld\n", k);
        loop(i, 1 << n){//prva
            dp[k][i] = inf;
            ll cost = 0;
            //dodaj cost
            loop(j, n)
                cost += (grid[j][k])^(i >> j & 1);


            loop(j, 1 << n){//prejsnja
                if(compatible(i, j, n)){
                    dp[k][i] = min(dp[k][i],   dp[k-1][j] + cost);
                    //printf("state %lld , prev %lld=> cost %lld\n", i, j, dp[k][i]);
                }
            }
            
        }
    }

    ll res = inf;
    loop(i, 1 << n) res = min(res, dp[m-1][i]);
    cout << res << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}