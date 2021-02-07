/**
 * Author: MatijaL
 * Time: 2021-01-09 10:15:01
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
    string s = "";
    if(n == 1){
        cout << 9 << endl;
        return;
    }
    if(n==2) {
        cout << 98 << endl;
        return;
    }
    s += "98";
    int cur = 9;
    loop(i, n-2){
        s += '0' + cur;
        cur++;
        if(cur == 10) cur =0;
    }
    cout << s << endl;
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
