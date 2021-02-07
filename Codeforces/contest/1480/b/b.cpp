/**
 * Author: MatijaL
 * Time: 2021-02-07 15:35:02
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
    int A, B, n;
    cin >> A >> B >> n;
    ll td = 0;

        

    vector<ll> u(n);
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    loop(i, n) cin >> u[i];



    ll worst = -1;
    loop(i, n){
        ll a, b;
        a = v[i];
        b = u[i];
        worst = max(worst, a); 

        ll cnt = b/A;
        if(b%A) cnt++;

        td += a*cnt;
    }
    
    //cout << td << " " << worst << endl;
    if(td <= B) cout << "YES" << endl;
    else{
        ll surplus = abs(B-td);
        if(surplus < worst) cout << "YES" << endl;
        else cout << "NO" << endl;
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
