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
#define mod n
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    
    int st_enk = 0;
    int id = -1;
    loop(i, n){
        int e = v[i];
        if(e==1) {st_enk++;id=i;}
        }
        
    if(st_enk!=1){
        cout << "NO" << endl;
        return;
    }
    
    FOR(i, 1, n-1){
        //preveri narascanje
        int prev = v[(id+i-1+n)%mod];
        int cur = v[(id+i)%mod];
        
        if(cur>prev and cur-prev>1){
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    return;
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
