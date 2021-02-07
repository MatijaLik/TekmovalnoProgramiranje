/**
 * Author: MatijaL
 * Time: 2021-01-09 10:15:01
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
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n) cin >> a[i];
    int cnt = 0;
    int flag[n];
    memset(flag, 0, sizeof flag);

    FOR(i, 1, n-2){
        if(a[i] > a[i+1] and a[i] > a[i-1]) flag[i] = 1;
        if(a[i] < a[i+1] and a[i] < a[i-1]) flag[i] = 1;
        if(flag[i]) cnt++;
    }

    int mx = 0;
    int cr = 0;
    FOR(i, 1, n-2){
        if(flag[i]) cr++;
        else cr = 0;
        mx = max(cr, mx);
    }

    mx = min(mx, 3);
    
    if(mx == 2){
        if(flag[1] and flag[2]) mx = 2;
        else if(flag[n-3] and flag[n-2]) mx = 2;
        else  mx = 1;
    }
    cout << cnt - mx << endl;
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
