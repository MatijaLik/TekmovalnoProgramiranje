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
#define inf 1000000100
#define mod 1000000007

void solve(){
    ll ans = 0;
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);

    loop(i, n) cin >> a[i];
    loop(i, n) cin >> b[i];

    ll minA = inf;
    ll minB = inf;
    loop(i, n){
        minA = min(minA, a[i]);
        minB = min(minB, b[i]);
    }

    //get cost
    loop(i, n){
        ll da = a[i] - minA;
        ll db = b[i] - minB;

        //damo hkrati


        //se posebej
        ans += max(da, db);
    }

    cout << ans << endl;
    
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