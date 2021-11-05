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

bool solve(){
    int a, b;
    cin >> a >> b;

    
    //binary search
    ll p1 = 0;
    ll p2 = min(a/3, b/3);
    ll mid;
    while(p1 <= p2){
        mid = (p1+p2)/2;
        ll as = a - 3*mid;
        ll bs = b - 3*mid;

        ll big = max(as, bs);
        ll smol = min(as, bs);

        //cout << mid << endl;

        if(2*smol > big) p1 = mid+1;
        else if(2*smol == big) return 1;
        else p2 = mid-1;
    }
    return 0;


}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}