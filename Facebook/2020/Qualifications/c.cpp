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

void solve(){
    ll n;
    cin >> n;

    pair<int, int> trees[n];

    loop(i, n){
        ll p, h;
        cin >> p >> h;
        trees[i] = mp(p, h);
    }

    

    ll ans = 0;

    map<ll, ll> longestFromLeft;
    map<ll, ll> longestFromRight;


    

    sort(&trees[0], &trees[0] + n);

    

    for(auto tree : trees){    
        ll p = tree.fs;    
        ll h = tree.sc;

        longestFromLeft[p+h] = max(longestFromLeft[p+h], longestFromLeft[p] + h);

        ans = max(ans, longestFromLeft[p+h]);

    }

    
    
    reverse(&trees[0], &trees[0] + n);
    for(auto tree : trees){    
        ll p = tree.fs;    
        ll h = tree.sc;

        longestFromRight[p-h] = max(longestFromRight[p-h], longestFromRight[p] + h);
        
        ans = max(ans, longestFromRight[p-h]);

        ans  = max(ans, longestFromRight[p-h] + longestFromLeft[p-h]); 
    }

    cout << ans << endl;

    

}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    freopen("timber_input.txt", "r", stdin);
    freopen("timber_output.txt", "w", stdout);
    int t;
    cin >> t;
    loop(i, t){
        printf("Case #%d: ", i+1);
        solve();
    }
}