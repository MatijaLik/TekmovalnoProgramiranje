/**
 * Author: MatijaL
 * Time: 2020-12-26 23:11:41
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
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    loop(i, n) cin >> a[i];
    sort(all(a));
     
    if(n==1){
        loop(i, m){
            ll b;
            cin >> b;
            cout << a[0] + b << " ";
        }
        cout << endl;
    }else{
        ll g = a[1] - a[0];
        FOR(i, 2, n-2){
            g = gcd(g, a[i+1] - a[i]);
        }
        loop(i, m){
            ll b;
            cin >> b;
            cout << gcd(a[0]+b, g) << " ";
        }
        cout << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
solve();   
}
