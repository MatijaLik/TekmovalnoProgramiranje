/*
 * Author: MatijaL
 * Time: 2020-08-16 19:01:25
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

vector<ll> r,g,b;
int memo[202][202][202];

ll dp(int rr,int gr,int br){
   if(memo[rr][gr][br] != -1) return memo[rr][gr][br]; 
   ll best = 0;
   //probajmo vse kombinacije
   if(rr and gr){
       best = max(best, dp(rr-1, gr-1, br) + r[rr-1]*g[gr-1]);
   }if(gr and br){
       best = max(best, dp(rr, gr-1, br-1) + g[gr-1]*b[br-1]);
   }if(rr and br){
       best = max(best, dp(rr-1, gr, br-1) + r[rr-1]*b[br-1]);
   }
   return memo[rr][gr][br] = best;
}


void solve(){
    loop(i, 202)loop(j, 202)loop(k, 202) memo[i][j][k] = -1;
    int R, G, B;
    cin >> R >> G >> B;
    loop(i, R){
        ll a;
        cin >> a;
        r.pb(a);
    }
    loop(i, G){
        ll a;
        cin >> a;
        g.pb(a);
    }
    loop(i, B){
        ll a;
        cin >> a;
        b.pb(a);
    }
    
    sort(all(r));
    sort(all(g));
    sort(all(b));

    cout << dp(R,G,B) << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

