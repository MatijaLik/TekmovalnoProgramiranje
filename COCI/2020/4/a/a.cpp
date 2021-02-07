/**
 * Author: MatijaL
 * Time: 2021-01-16 15:01:02
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
    int n;
    cin >> n;
    set<int> black;
    loop(i, n){
        int t;
        cin >> t;
        black.insert(t);
    }
    int b;
    cin >> b;
    int cnt = 0;
    loop(B, b){
        int k;
        cin >> k;
        vector<int> v(k);
        loop(i, k) cin >> v[i];

        bool gud = 1;
        for(auto e : v){
            if(black.count(e)) gud=0;
        }
        if(gud) cnt++;
    }
    cout << cnt << endl;
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
