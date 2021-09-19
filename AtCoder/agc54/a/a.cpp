/**
 * Author: MatijaL
 * Time: 2021-06-27 13:39:14
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
    string s;
    cin >> s;

    //int n = s.size();
    if(s[0] != s[n-1]){
        cout << 1 << endl;
        return;
    }

    char c = s[0];
    FOR(i, 1, n-3){
        if(s[i] != c and s[i+1] != c){
            cout << 2 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
