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
    if(n == 1){
        int a;
        cin >> a;
        cout << "YES" << endl;
        return;
    }
    vector<ll> v(n);
    loop(i, n){
        cin >> v[i];
    }

    sort(all(v));
    ll prev = v[0];
    FOR(i, 1, n-1){
        if(abs(prev - v[i]) > 1){
            cout << "NO" << endl;
            return;
        }
        prev = v[i];
    }
    cout << "YES" << endl;

    
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