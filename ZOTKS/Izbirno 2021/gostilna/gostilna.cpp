/**
 * Author: MatijaL
 * Time: 2021-05-27 16:11:29
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

#define DEBUG 0
const int MOD = 1000000007;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}



void solve(){
    ll H, W, N;
    cin >> H >> W >> N;


    vector<pair<int, int>> compatibleMasks[(1<<H)];
    //precompute
    FOR(a, 0, (1<<H)-1){
        FOR(b, 0, (1<<H)-1){

            bool bad = 0;
            int used = 0;
            //ali je b okej
            FOR(i, 1, H-1){
                if(b & (1 << i) and b & (1 << (i-1))){
                    bad = 1;
                    break;
                }
            }

            FOR(i, 0, H-1){
                if(b & (1<<i)){
                    used++;
                    if(a & (1<<i)) bad = 1;
                    if(i > 0 and a & (1<<(i-1))) bad =1;
                    if(i < H-1 and a & (1<<(i+1))) bad =1;
                }
            }

            if(!bad) compatibleMasks[a].pb(mp(b, used));
        }
    }


    if(DEBUG)
    FOR(i, 0, (1<<H)-1){
        printf("mask %d\n", i);
        for(auto e : compatibleMasks[i]) printf("%d ", e.fs);
        printf("\n");
    }


    ll dp[(1 << H)][W+1][N+1];

    memset(dp, 0, sizeof dp);


    //nafilaj
    FOR(mask, 0, (1<<H)-1)
        FOR(w, 0, W)
            dp[mask][w][0] = 1;
    
    FOR(mask, 0, (1<<H)-1)
        FOR(n, 1, N)
            dp[mask][0][n] = 0;

    FOR(w, 1, W){
        FOR(mask, 0, (1<<H)-1){
            FOR(n, 1, N){
                if(DEBUG)printf("%d %d %d\n", w, mask, n);
                for(auto e : compatibleMasks[mask]){
                    int used = e.sc;
                    int newMask = e.fs;

                    if(used > n) continue;

                    dp[mask][w][n] = add(dp[mask][w][n], dp[newMask][w-1][n-used]);
                }
            }
        }
    }

    cout << dp[0][W][N] << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
