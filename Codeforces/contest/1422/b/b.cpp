/**
 * Author: MatijaL
 * Time: 2020-10-04 18:05:01
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

void solve(){
    int n, m;
    cin >> n >> m;
    ll a[n][m];
    loop(i, n)loop(j, m) cin >> a[i][j];

    //prvi kvadrant
    ll res = 0;
    loop(i, n/2) loop(j, m/2){
        vector<ll> v;
        v.pb(a[i][j]);
        v.pb(a[n-i-1][j]);
        v.pb(a[i][m-j-1]);
        v.pb(a[n-i-1][m-j-1]);
        
        sort(all(v));
        ll avg = v[1];
        //sum
        //ll sum = 0;
        //for(auto e : v) sum += e;
        //ll avg = sum/4;
        for(auto e : v){
            res += abs(e - avg);
        }
    }
    
    //sredina??
    if(n%2 == 1){
        loop(i, m/2){
            ll c = a[n/2][i];
            ll b = a[n/2][m-i-1];
            res += abs(c-b);
        }
    }

    if(m%2 == 1){
        loop(i, n/2){
            ll c = a[i][m/2];
            ll b = a[n-i-1][m/2];
            res += abs(c-b);
        }
    }
    cout << res << endl;
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
