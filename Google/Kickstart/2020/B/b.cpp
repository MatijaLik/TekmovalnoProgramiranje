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

void solve(int cs){
    ll ans;
    ll n, d;
    cin >> n >> d;
    vector<ll> x;
    loop(i, n){
        ll temp;
        cin >> temp;
        x.pb(temp);
    }

    reverse(all(x));
    ans = d;
    loop(i, n){
        ll reduce = ans%x[i];
        ans -= reduce;
    }


    printf("Case #%d: %lld\n", cs, ans);
}


int main(){
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}