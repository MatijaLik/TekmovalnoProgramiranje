/**
 * Author: MatijaL
 * Time: 2020-11-16 09:30:26
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

ll countInverses(const vector<ll> &a, ll x){
    ll ans = 0;
    //printf("%lld\n", x);
    multiset<int> s; 
    for(int i = a.size() - 1; i >= 0; i--){
        ll e = a[i];
        ll num = e ^ x;
        
        s.insert(num); 
        auto it = s.lower_bound(num); 
        ans += distance(s.begin(), it); 

        //printf("%lld %lld\n", num, distance(s.begin(), it));
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    loop(i, n) cin >> v[i];

    ll x = 0;
    for(ll bit = 30; bit >= 0; bit--){
        ll increment = (1LL << bit);
        ll cost0 = countInverses(v, x);
        ll cost1 = countInverses(v, x+increment);
        //printf("%lld %lld; %lld | %lld\n", x, bit, cost0, cost1);
        if(cost1 < cost0) x += increment;
        
    }
    printf("%lld %lld\n", countInverses(v, x), x);
    //for(auto e : v) cout << (e^x) << " ";
    //cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
