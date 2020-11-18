/**
 * Author: MatijaL
 * Time: 2020-11-01 12:05:02
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);

    loop(i, n)cin >> a[i];
    loop(i, n)cin >> b[i];
    sort(all(a));
    sort(all(b));
    reverse(all(b));

    loop(i, n){
        if(a[i]+b[i]>x){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
