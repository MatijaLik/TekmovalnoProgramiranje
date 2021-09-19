/**
 * Author: MatijaL
 * Time: 2021-08-22 18:01:23
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

const ll limit = 10e5;

void solve(){
    vector<int> primes;
    bool div[limit+1];
    memset(div, 0, sizeof div);
    FOR(i, 2, limit){
        if(div[i] == 0){
            primes.pb(i);
            for(ll j = i*i; j <= limit; j += i) div[j] = i;
        }
    }

    vector<int> facts;
    ll n;
    cin >> n;
    for(auto p : primes){
        while(n % p == 0){
            n /= p;
            facts.pb(p);
        }
    }
    if(n != 1) facts.pb(n);

    print(facts);

    int s = facts.size();
    unordered_set<int> divs;
    for(ll msk = 0; msk < (1ll << s); msk++){
        ll prod = 1;
        loop(i, s) if( msk & (1ll << i)) prod *= facts[i];
        divs.insert(prod);
    }

    printf("%lld\n", divs.size());
    for(auto e : divs) printf("%lld ", e);
    printf("\n");
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
