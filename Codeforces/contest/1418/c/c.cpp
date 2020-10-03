/**
 * Author: MatijaL
 * Time: 2020-09-19 20:45:01
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
int n;
int memo[200100][2];
vector<int> a;
int dp(int pos, int turn){
    if(memo[pos][turn] != -1) return memo[pos][turn];
    if(pos >= n) return memo[pos][turn] = 0;

    //friend
    int best = inf;
    if(turn == 0){
        //make one move
        int cost = a[pos];
        best = min(best, cost + dp(pos+1, 1));

        //two moves
        cost += a[pos+1];
        best = min(best, cost + dp(pos+2, 1));
    }
    else{
        //me
        best = min(best, dp(pos+1, 0));
        best = min(best, dp(pos+2, 0));

    }
    return memo[pos][turn] = best;
}
void solve(){
    cin >> n;
    FOR(i, 0, n+10){
        memo[i][1] = -1;
memo[i][0] = -1;
    }
    a.clear();
    loop(i, n){
        int temp;
        cin >> temp;
        a.pb(temp);
    }
    a.pb(0);
    cout << dp(0, 0) << endl;
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
