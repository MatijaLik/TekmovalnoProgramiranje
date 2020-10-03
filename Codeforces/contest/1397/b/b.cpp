/**
 * Author: MatijaL
 * Time: 2020-08-30 16:35:02
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
const ll inf  = 1100000000;
#define mod 1000000007
double limit;
vector<ll> v;


 

ll test(ll c){
    ll ans = 0;
    ll base = 1;
    for(auto e : v){
        ans += abs(e - base);
        base *= c;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    //limit = pow((double)(inf*inf),1.0/(double) (n-1));
    //limit = ceil(limit);
    loop(i, n){
        int e;
        cin >> e;
        v.pb(e);
    }
    sort(all(v));

    double root = (double)1/((double)(n-1));
    limit = (long long)pow((double)((n+1)*inf), root);
    ll best = inf*inf;
    ll bestc = -1;
    FOR(c, 1, limit){
        best = min(best, test(c));
        if(best == test(c)) bestc = c;
    }
    cout << best << endl;
}


int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
