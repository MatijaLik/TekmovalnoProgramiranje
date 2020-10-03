/*
 * Author: MatijaL
 * Time: 2020-08-16 15:39:37
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
    ll x, y, z;
    cin >> x >> y >> z;
    multiset<ll> s;
    s.insert(x);
    s.insert(y);
    s.insert(z);
    if(s.count(max(max(x, y), z)) >= 2){
        cout << "YES" << endl;
        cout << min(x, min(y, z)) << " ";
        cout << min(x, min(y, z)) << " ";
        cout << max(x, max(y, z)) << endl;
    }else{
        cout << "NO" << endl;
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