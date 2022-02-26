/**
 * Author: MatijaL
 * Time: 2022-02-06 15:35:02
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
    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << "YES" << endl;
        FOR(i, 1, n*k){
            cout << i << endl;
        }
        return;
    }
    
    if(n%2){
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    int cnt = 0;
    for(int e = 2; e <= n*k; e += 2){
        cout << e << " ";
        cnt++;
        if(cnt==k){
            cout << endl;
            cnt=0;
        }
    }
    for(int e = 1; e <= n*k; e += 2){
        cout << e << " ";
        cnt++;
        if(cnt==k){
            cout << endl;
            cnt=0;
        }
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
