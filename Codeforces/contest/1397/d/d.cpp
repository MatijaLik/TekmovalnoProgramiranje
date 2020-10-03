/**
 * Author: MatijaL
 * Time: 2020-08-30 16:35:02
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


void endgame(int loser){
    if(loser == 0) cout << "HL" << endl;
    else cout << "T" << endl;
}



void solve(){
    int n;
    cin >> n;
    vector<int> v;
    int sum = 0;
    loop(i, n){
        int a;
        cin >> a;
        sum += a;
        v.pb(a);
    }
    int mx = -1;
    for(auto e : v) mx = max(mx, e);
    ll rem = sum - mx;
    if(rem % 2 == 1) cout << "HL" << endl;
    else cout << "T" << endl;
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
