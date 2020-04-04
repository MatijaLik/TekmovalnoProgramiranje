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
#define debug(x) cout << "# " << x << endl;

#define limit 1000


int gcd(int a, int b)
{
   return b == 0 ? a : gcd(b, a%b);
}


vector<ll> primes;
bool b[limit];
ll divisor[limit];

void erat(){
    FOR(i, 2, limit){
        if(b[i]==0){
            primes.pb(i);
            for(ll j = i*i; j < limit; j += i){
                b[j] = 1; 
                divisor[j]=i;
            }
        }
    }
    return;
}


int main(){
    erat();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> nums;
        set<ll> used;
        ll cnt = 0;
        map<ll, ll> fag;
        loop(i, n){
            ll temp;
            cin >> temp;
            nums.pb(temp);
            for(ll p : primes){
                if(temp % p == 0){
                    if(!used.count(p)){
                        used.insert(p);
                        fag[p] = cnt;
                        cnt++;

                    }
                    break;
                }
            }
        }
            
        cout << cnt << endl;
        for(ll temp : nums){
            for(ll p : primes){
                if(temp % p == 0){
                    cout << fag[p]+1 << " ";
                    break;
                }
                
            }
        }

        cout << endl;





    }
}