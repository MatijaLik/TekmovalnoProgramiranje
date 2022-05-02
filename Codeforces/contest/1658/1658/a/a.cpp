/**
 * Author: MatijaL
 * Time: 2022-03-27 16:35:02
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
    int ans = 0;
    int len = 0;
    loop(i, n){
        
        //enojna
        if(i!=0 and i!=n-1){
            if(s[i] =='1' and s[i-1]=='0' and s[i+1]=='0') ans++;
        }
        
        
        char e = s[i];
        if(e=='1'){
            if(len!=0)
                ans += 2*(len-1);
            len=0;
        }else len++;
    }
    if(len!=0)
        ans += 2*(len-1);
    cout << ans << endl;
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
