/**
 * Author: MatijaL
 * Time: 2021-09-12 16:35:12
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
    int swp = 0;
    string s;
    cin >> s;
    char b = s[0];
    for(auto e : s){
        if(e != b){
            swp++;
            b = e;
        }
    }
    if(swp >= 2) {
        if(swp == 2 and s[0] == '1') cout << 1 << endl;
        else cout << 2 << endl;
    }
    else if(swp == 1) cout << 1 << endl;
    else cout <<1- (s[0]-'0') << endl;
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
