/**
 * Author: MatijaL
 * Time: 2021-02-13 17:34:39
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
#define inf 1000000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;


int n, q;
ll memo[205][205];
    vector<ll> v;
ll dp(int beg, int pos){
    if(memo[beg][pos] != -inf) return memo[beg][pos];

    if(pos == n) return 0; 



    ll best = -1000LL*inf;
    //daj zram
    if(pos != n-1) best = dp(beg, pos+1);

    //odrezi
    ll mn = inf;
    ll mx = -inf;
    FOR(i, beg, pos){
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }

    best = max(best, mx-mn + dp(pos+1, pos+1));




   // printf("dp %d %d --> %lld\n", beg, pos, best);
    return memo[beg][pos] = best;
}

void solve(){
    cin >> n >> q;
    loop(i, n){
        ll e;
        cin >> e;
        v.pb(e);
    };



    while(q--){
        loop(i, 205) loop(j, 205) memo[i][j] = -inf;
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        FOR(i, a, b){
            v[i] += c;
        }
       cout <<  dp(0, 0) << endl;
    }
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
