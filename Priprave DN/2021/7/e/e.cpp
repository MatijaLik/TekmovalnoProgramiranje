/**
 * Author: MatijaL
 * Time: 2021-01-27 22:34:02
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
#define mod 2147483647
#define print(v) for(auto e : v) cout << e << " "; cout << endl;
#define limit 20000100
bool b[limit];
ll divisor[limit];

void solve(){
    vector<ll> primes;
    primes.reserve(1000200);

    FOR(i, 2, limit){
        if(primes.size() == 1000200) break;
        if(b[i]==0){
            primes.pb(i);
            for(ll j = i*i; j < limit; j += i){
                b[j] = 1; 
                divisor[j]=i;
            }
        }
    }


    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(all(primes), g);

    int n, m;
    cin >> n >> m;

    ll nodeHash[n];
    loop(i, n) nodeHash[i] = 1;
    loop(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        assert(primes[b] != 0);
        assert(primes[a] != 0);
        nodeHash[a] *= primes[b];
        nodeHash[b] *= primes[a];

        nodeHash[a] %= mod;
        nodeHash[b] %= mod;
    }

    ll ans = 0;

    vector<ll> hashes;
    unordered_map<ll, ll> cnt;
    loop(i, n){
        //cout << nodeHash[i] << endl;

        cnt[nodeHash[i]]++;
        cnt[(nodeHash[i]*primes[i])%mod]++;
        
        
        if(cnt[nodeHash[i]] == 1) hashes.pb(nodeHash[i]);
        if(cnt[(nodeHash[i]*primes[i])%mod] == 1) hashes.pb((nodeHash[i]*primes[i])%mod);
    }


    for(auto e : hashes){
        ll x = cnt[e];
        //printf("%lld %lld\n", e, x);
        ans += (x*(x-1))/2;
    }

    cout << ans << endl;
}

int main(){
    //cout << primes.size() << endl;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
