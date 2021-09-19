/**
 * Author: MatijaL
 * Time: 2021-06-20 14:20:14
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


ll a[200500][15];
#define limit 100500
void add(int i, int k, ll val){
    for(; i < limit; i += i & -i) a[i][k] += val;
}

unsigned long long query(int i, int k){
    unsigned long long ans = 0;
    for(; i > 0; i -= i & -i){
        ans += a[i][k];
    }
    return ans;
}



void solve(){
    int n, K;
    cin >> n >> K;
    K++;

    vector<int> v(n);
    loop(i, n) cin >> v[i];

    for(auto e : v){
        add(e, 1, 1);
        FOR(k, 1, K){
            //printf("%d %d %lld\n", e, k, query(e-1, k));
            add(e, k+1, query(e-1, k));
        }
    }

    ll ans = query(limit, K);
    cout << ans << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
