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
#define mod 1000037
#define mod2 1000000007

#define debug(x) cout << "# " << x << endl;


#define nlimit 100010

ll memo[nlimit][5];

ll dp(ll n, ll k){
    if(n == 0 or k == 0) return memo[n][k] = 1;
    if(n == k) return memo[n][k] = 1;
    if(memo[n][k]!= 0) return memo[n][k];

    return memo[n][k] = (dp(n-1, k) + dp(n-1, k-1))%mod;
}


ll hs[nlimit];
ll N;
map<ll, ll> cnt;//count hahses
vector<ll> hashes[nlimit]; //hashes by length
map<ll, vector<ll>> ix; //indexes
//map<ll, vector<ll>> hahses; //za vsako dolzino

ll shift[nlimit];


int main(){
    shift[1] = 27;
    loop(i, nlimit){
        shift[i+2] = (shift[i+1]*27)%mod2;
    }
    cin >> N;
    string s;
    cin >> s;
    ll rhs = 0;
    for(ll i = N-1; i >= 0; i--){
        char c = s[i];
        ll value = (int) c - 96;
        rhs *= 27;
        rhs += value;
        rhs %= mod2;
        hs[i] = rhs;
    }

    //debug(1);
    FOR(i, 0, N-1){
        FOR(j, i, N-1){
            ll len = j-i+1;

            ll lastHash = (hs[j+1]*shift[len])%mod2;
            ll firstHash = hs[i];
            ll res = (firstHash-lastHash)% mod2;
            while(res<0) res += mod2;

            //cout << res << endl;
            if(cnt[res] == 0){
                hashes[len].pb(res);
                cnt[res] = 1;
                ix[res].pb(i);
                //cout << "new" << endl;
            }else{
                if(ix[res].back()+len <= i){
                    //cout << "gud" << endl;
                    cnt[res]++;
                    ix[res].pb(i);
                }else{
                    //cout << "error " << res << endl; 
                }
            }
            
        }
    }


    //debug(2);
    ll maxd = 0;
    ll besthash;
    ll sum = 0;
    for(ll len = N; len >= 0; len--){
        sum = 0;
        for(auto hsh : hashes[len]){
            if(cnt[hsh]>=3){
                //cout << hsh << endl;
                //cout << cnt[hsh] << endl;

                //preveri prekrivanje
                sum += dp(cnt[hsh], 3);
                sum %= mod; 
                maxd = len;
                besthash = hsh;
                //cout << sum << endl;
                //cout << "#####" << endl;
            }
        }
        if(sum) break;
    }
    //cout << dp(3, 3) << endl;
    //cout << dp(5, 3) << endl;
    //cout << dp(10, 3) << endl;
    //debug(3);
    cout << ix[besthash][0]+1 << " " << ix[besthash][1]+1 << " " << ix[besthash][2]+1 << " " << maxd << endl;
    cout << sum << endl;

}