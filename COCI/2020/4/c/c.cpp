/**
 * Author: MatijaL
 * Time: 2021-01-16 15:59:38
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

int f(ll a, ll b){
    
    int msa, msb;
    msa = -1;
    msb = -1;
    for(ll bit = 62; bit >= 0; bit--){
        if(a & (1LL << bit)){
            msa = bit;
            break;
        }
    }
    for(ll bit = 62; bit >= 0; bit--){
        if(b & (1LL << bit)){
            msb = bit;
            break;
        }
    }
    assert(msa >= 0 and msb >= 0);
    if(msa/4 == msb/4) return 1;
    if(msa/16 == msb/16) return 2;
    return 3;
}
void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    FOR(i, 1, n-1){
        FOR(j, 0, i-1){
            cout << f(v[i], v[j]) << " ";
        }
        cout << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
