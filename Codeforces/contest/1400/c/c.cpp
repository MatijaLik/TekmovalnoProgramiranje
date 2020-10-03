/**
 * Author: MatijaL
 * Time: 2020-08-25 16:35:02
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
#define inf 1000000000
#define mod 1000000007

void solve(){
    int x;
    string s;
    cin >> s;
    cin >> x;
    string res = "";
    ll n = s.size();
    loop(i, n) res += '1';
    loop(i, n){
        char c = s[i];
        if(c == '1') continue;
        if(i+x < n) res[i+x] = '0';
        if(i-x >= 0) res[i-x] = '0';
    }
    
    //verify
    loop(i, n){
        char c = s[i];
        if(c == '0') continue;
        bool b1, b2;
        b1 = false;
        b2 = false;
        if(x+i < n) b1 = res[i+x] == '1';
        if(i-x >= 0) b2 = res[i-x] == '1';
        if(b1 == false and b2 == false){
            cout << -1 << endl;
            return;
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
