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
 
#define limit 100200
#define DEBUG 0
const ll INF = inf*1LL*inf;
 
//meet in the middle
vector<ll> makeSum(vector<int> v){
    vector<ll> ans;
    int n = v.size();
    for(ll i = 0; i < (1LL << n); i++){
        ll sum = 0;
        loop(j, n){
            if(i & (1LL << j)) sum += v[j];
        }
        ans.pb(sum);
    }
    return ans;
}
 
void compress(vector<ll> &v, vector<pll> &out){
    ll prev = -1;
    ll cnt = 0;
    for(auto e : v){
        if(e != prev){
            if(cnt != 0) out.pb(mp(prev, cnt));
            prev = e;
            cnt = 1;
        }
        else cnt++;
    }

    if(cnt != 0) out.pb(mp(prev, cnt));
    return;
}

int main(){
 
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n/2);
    vector<int> b(n-n/2);
 
    loop(i, n/2) cin >> a[i];
    loop(i, n-n/2) cin >> b[i];
 
    vector<ll> aSum = makeSum(a);
    vector<ll> bSum = makeSum(b);
 
    sort(all(aSum));
    sort(all(bSum));

    //strni iste
    vector<pll> aFin;
    vector<pll> bFin;
    
 
    compress(aSum, aFin);
    compress(bSum, bFin);


    ll ans = 0;
    int p = bFin.size() - 1;
    for(auto e : aFin){
        while(e.fs + bFin[p].fs >= x and p >= 0){
            if(e.fs + bFin[p].fs == x) ans+= e.sc * bFin[p].sc;
            p--;
        }
    }
    cout << ans << endl;
    return 0;
}