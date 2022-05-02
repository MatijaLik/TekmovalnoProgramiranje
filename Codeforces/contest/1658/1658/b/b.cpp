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
#define print(v) for(auto e : v) cout << e << " "; cout << endl;
const ll mod =  998244353;

const ll limit = 2000;
ll fact[limit];
void solve(){
    int n;
    cin >> n;
    if(n%2) cout << 0 << endl;
    else{
        cout << (fact[n/2]*fact[n/2])%mod << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fact[0]=1;
    FOR(i, 1, limit-1){
        fact[i] = (fact[i-1]*i)%mod;
    }
    
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
