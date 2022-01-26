/**
 * Author: MatijaL
 * Time: 2022-01-22 15:35:03
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
    int l, r, k;
    cin >> l >> r >> k;
    if(l==r){
        if(l == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
    }
    int odd = 0;
    if(l%2) odd = 1 + (r-l)/2;
    else odd = (r-l+1)/2;

    if(k>=odd) cout << "YES" << endl;
    else cout << "NO" << endl;
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
