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


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> w;

    loop(i, n) cin >> a[i];

    ll ones = 0;

    loop(i, k){
        int temp;
        cin >> temp;
        if(temp == 1) ones++;
        else w.pb(temp);
    }

    sort(all(a));

    sort(all(w));
    reverse(all(w));

    int p1 = 0;
    int p2 = n-1;

    ll ans = 0;
    loop(i, ones){
        ans += 2*a[p2];
        p2--;
    }

    for(auto frend : w){
        ans += a[p2];
        ans += a[p1];
        
        loop(i, frend-1){
            p1++;
        }

        p2--;
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
    while(t--){
        solve();
    }
}