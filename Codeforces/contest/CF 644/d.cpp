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


#define limit 100000

vector<ll> primes;
bool b[limit];

void erat(){
    FOR(i, 2, limit){
        if(b[i]==0){
            primes.pb(i);
            for(ll j = i; j < limit; j += i){
                b[j] = 1; 
            }
        }
    }
}

ll decomposite(ll a, ll b){

    if(a <= b) return 1;

    ll cur = a;

    vector<ll> factors;

    for(ll prime : primes){
        while(cur % prime == 0){
            cur /= prime;
            factors.pb(prime);
        }
    }

    if(factors.size() == 0) return a;//preveliko prastevilo

    ll x = factors.size();
    ll best = 1;

    loop(i, ((ll)1<< x)){
        ll prod = 1;
        loop(j, x){
            if(i & ((ll)1 << j)) prod *= factors[j];
        }

        if(prod <= b){
            best = max(best, prod);
        }
        //cout << prod << endl;
    }

    return a/best;
}


int main(){
    memset(b, 0, sizeof b);

    int t;
    cin >> t;
    erat();
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << decomposite(a, b) << endl;
    }
}