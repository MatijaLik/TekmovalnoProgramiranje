/**
 * Author: MatijaL
 * Time: 2020-11-04 15:03:21
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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n) cin >> a[i];

    vector<int> v;
    v.pb(1);
    int id = 0;
    int prev = 1;

    for(auto e : a){
        
       
        if(e == 1) continue;


        if(e > prev) v.pb(v[id]+1);
        if(e < prev){
            id++;
            v.pb(v[id]+1);
        }
        prev = e;

        
    }
    cout << v[v.size()-1]-1 << endl;
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