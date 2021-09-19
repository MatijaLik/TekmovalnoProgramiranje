/**
 * Author: MatijaL
 * Time: 2021-08-20 22:30:59
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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    vector<int> L(n), R(n);
    vector<int> l(n+1, INT_MAX), r(n+1, INT_MIN);
    loop(i, n){
        int e = v[i];
        int j = lower_bound(all(l), e) - l.begin();
        L[i] = j+1;
        l[j] = e;
    }
    loop(i, n){
        int e = v[n-i-1];
        int j = upper_bound(all(r), e-x) - r.begin();
        R[n-i-1] = n-j+2;

        j = upper_bound(all(r), e) - r.begin();
        r[j-1] = e;
    }


    int mx = 0;
    loop(i, n) mx = max(mx, L[i] + R[i]);
    cout << mx-1 << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
