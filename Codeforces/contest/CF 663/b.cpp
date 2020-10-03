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
    ll ans = 0;

    ll n, m;
    cin >> n >> m;

    loop(i, n){
        string s;
        cin >> s;
        if(s[m-1] == 'R') ans++;

        if(i == n-1){
            for(auto c : s){
                if(c == 'D') ans++;
            }
        }
    }
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