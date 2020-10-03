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
    int n;
    cin >> n;
    if(n < 31){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    n -= 30;
    if(n == 6 or n == 10  or n == 14) printf("6 10 15 %d\n", n-1);
    else printf("6 10 14 %d\n", n);
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    

    int t;
    cin >> t;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(t--){
        solve();
    }    
}