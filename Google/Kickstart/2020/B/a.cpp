#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl


void solve(int cs){
    int n;
    cin >> n;
    vector<int> h;
    FOR(i, 1, n){
        ll temp;
        cin >> temp;
        h.pb(temp);
    }
    ll cnt = 0;
    FOR(i, 0, n-1){
        if(i == 0 or i == n-1) continue;
        if(h[i] > h[i-1] and h[i] > h[i+1]) cnt++;
    }


    printf("Case #%d: %d\n", cs, cnt);
}

int main(){
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}