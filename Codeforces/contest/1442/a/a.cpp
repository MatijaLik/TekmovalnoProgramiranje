/**
 * Author: MatijaL
 * Time: 2020-11-03 17:38:36
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
    vector<int> v(n);
    loop(i, n) cin >> v[i];

    int prev =  v[0];
    bool slope = 0;//dol
    int flip = 0;
    FOR(i, 1, n-1){
        int cur = v[i];
        int diff = cur-prev;

        if(diff <= 0){
            if(slope == 1){
                slope = 0;
                flip++;
            }
        }else{
            if(slope == 0){
                slope = 1;
                flip++;
            }
        }
    }
    if(flip <= 1 or (flip == 2 and slope == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
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
