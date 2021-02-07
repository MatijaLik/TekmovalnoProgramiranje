/**
 * Author: MatijaL
 * Time: 2021-01-27 22:34:02
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
#define mod 2147483647
#define print(v) for(auto e : v) cout << e << " "; cout << endl;
#define limit 20000100


ll HASH(std::set<int> const& vec){
  ll seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}
set<int> s[1000200];
void solve(){
    
    int n, m;
    cin >> n >> m;

    
    loop(i, m){
        int a, b;
        cin >> a >> b;
        a;
        b;

        s[a].insert(b);
        s[b].insert(a);
    }


    ll ans = 0;

    unordered_map<int, int> cnt;
    FOR(i, 1, n){
        //cout << nodeHash[i] << endl;

        ans += cnt[HASH(s[i])];
        cnt[HASH(s[i])]++;

        s[i].insert(i);

        ans += cnt[HASH(s[i])];
        cnt[HASH(s[i])]++;   
    }

    cout << ans << endl;
}

int main(){
    //cout << primes.size() << endl;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
