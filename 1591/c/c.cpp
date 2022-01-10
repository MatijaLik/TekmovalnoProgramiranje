/**
 * Author: MatijaL
 * Time: 2021-12-12 16:15:02
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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a, b;
    loop(i, n){
        int t;
        cin >> t;
        if(t > 0) a.pb(t);
        if(t < 0) b.pb(t);
    }
    sort(all(a));
    sort(all(b));
    ll sa=0, ma=0;
    ll sb=0, mb=0;
    
    reverse(all(a));
    for(int i = 0; i < a.size(); i+=k){
        ma = max(a[i], ma);
        sa += 2*a[i];
    }
    
    for(int i = 0; i < b.size(); i+=k){
        mb = max(-b[i], mb);
        sb += -2*b[i];
    }
    
    cout << min(sa+sb-ma , sa+sb-mb) << endl;
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
