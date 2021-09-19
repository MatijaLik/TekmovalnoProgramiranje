/**
 * Author: MatijaL
 * Time: 2021-05-06 16:19:50
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

ll exp(ll a, ll e){
    ll ans = 1;
    loop(i, e) ans *= a;
    return ans;
}


void solve(){
    int N, L;
    cin >> N >> L;


    ll ans = 0;

    FOR(a, 1, L){
        FOR(b, a, L){
            ll sum = exp(a, N) + exp(b, N);
            if(ceil((double)pow(sum, 1.0/N)) == floor((double)pow(sum, 1.0/N))
            
                and 

                pow(sum, 1.0/N) <= L
            ){
                ans++;
                printf("%lld %lld  = %d %lf\n", a, b, sum, pow(sum, 1.0/N));
            }
        }
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
