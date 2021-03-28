/**
 * Author: MatijaL
 * Time: 2021-03-27 12:33:43
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

#define DEBUG 1


void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    loop(i, n){
        int x, y;
        cin >> x >> y;
        v[i] = mp(x, y);
    }

    sort(all(v));

    double dist[n][n];
    FOR(i, 0, n-1)FOR(j, 0, n-1){
        dist[i][j] = sqrt(
            (v[i].fs - v[j].fs)*(v[i].fs - v[j].fs) 
            +
            (v[i].sc - v[j].sc)*(v[i].sc - v[j].sc)
            );
    }

    if(n==2){
        printf("%.6F\n", dist[0][1]);
        return;
    }

    const int limit = 3510;
    double dp[limit][limit];

    loop(i, limit)loop(j, limit) dp[i][j] = inf;

    dp[0][0] = 0;

    double best = inf;
    //push dp
    FOR(s1, 0, n-2){
        //damo ga gor
        //dp[p][p]
        FOR(s2, 0, n-2){
            if(s1 == s2 and s1 != 0) continue;

            //naslednjik
            int nx = max(s1, s2) + 1;

            if(nx == n-1){
                //ta zadnji
                best = min(best, dp[s1][s2] + dist[nx][s1] + dist[nx][s2]);
                continue;
            }

            //daj ga levo
            dp[nx][s2] = min(dp[nx][s2], dp[s1][s2] + dist[nx][s1]);

            //daj ga desno
            dp[s1][nx] = min(dp[s1][nx], dp[s1][s2] + dist[nx][s2]);



        }
        
    }

    printf("%.6F\n", best);
    return;

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
