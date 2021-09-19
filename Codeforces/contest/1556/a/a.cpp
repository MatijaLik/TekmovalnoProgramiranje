/**
 * Author: MatijaL
 * Time: 2021-08-29 16:35:02
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
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void solve(){
    int c, d;
    cin >> c >> d;
    if(max(c, d) == 0) cout << 0 << endl;
    else if((c+d) % 2 == 0){
        if(c == d) {cout << 1 << endl;return;}
        cout << 2 << endl;
    }else{
        cout << -1 << endl;
    }
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
