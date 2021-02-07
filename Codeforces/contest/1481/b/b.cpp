/**
 * Author: MatijaL
 * Time: 2021-02-05 15:35:01
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
    vector<int> h(n);
    loop(i, n) cin >> h[i];

    loop(i, k){
        int pos = 0;
        while(pos < n-1 and h[pos] >= h[pos+1]) pos++;
        if(pos == n-1){
            cout << -1 << endl;
            return;
        }
        h[pos]++;
        if(i == k-1) cout << pos + 1 << endl;
    }
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
