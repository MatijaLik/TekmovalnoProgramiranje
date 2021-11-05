#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl


map<ll, ll> memo;
set<ll> memoS;

map<ll, ll> endFinder;
vector<ll> lookup;

ll dp(int start){
    //printf("dp %lld\n", start);

    if(memoS.count(start)) return memo[start];

    //dve zadevi
    memoS.insert(start);

    ll end = endFinder[start];

    //next
    auto t1 =  upper_bound(all(lookup), start);
    if(t1 == lookup.end()) return memo[start] = 1;
    int skip = *t1;


    //next After end
    auto t2 =  lower_bound(all(lookup), end);
    if(t2 == lookup.end()) return memo[start] = dp(skip);
    int watch = *t2;

    //printf("%lld %lld\n", skip, watch);


    ll ans = max(
        dp(watch) + 1,
        dp(skip)  
    );
    //printf("dp %lld ---> %lld\n", start, ans);
    return memo[start] = ans;
}
void solve(){
    int n;
    cin >> n;

    vector<pll> v;
    loop(i, n){
        int a, b;
        cin >> a >> b;
        v.pb(mp(a, b));
    }

    sort(all(v));
    int prev = -1;

    vector<pll> f;
    

    for(auto e : v){
        if(prev == e.fs) continue;
        else {
            f.pb(e);
            lookup.pb(e.fs);
            prev = e.fs;

            endFinder[e.fs] = e.sc;
        }
    }
    cout << dp(f[0].fs) << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();  
}