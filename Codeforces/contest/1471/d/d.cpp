/**
 * Author: MatijaL
 * Time: 2021-01-06 18:18:07
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
#define limit 1000100

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
void solve(){
    int N;
    cin >> N;
    int zero = 0;
    int other = 0;

    vector<int> v(N);
    vector<ll> rem;
    map<ll, int> cnt;

    loop(i, N) cin >> v[i];
    for(auto e : v){
        //factorise
        ll odd = 1;
        ll num = e;
        for(auto p : primes){
            if(num == 1) break;
            if(p*p > num){
                odd *= num;
                odd %= mod;
                break;
            }
            int count = 0;
            while(num % p == 0){
                count++;
                num /= p;
            }
            if(count % 2){
                odd *= p;
                odd %= mod;
            }
        }
        if(cnt[odd]==0) rem.pb(odd);
        cnt[odd]++;
    }
    int squares = 0;
    for(auto e : rem){
        zero = max(zero, cnt[e]);
        if(cnt[e] % 2 == 0 or e == 1) squares += cnt[e];
    }

    other = max(squares, zero);

    int Q;
    cin >> Q;
    loop(i, Q){
        ll w;
        cin >> w;
        if(w==0) cout << zero << endl;
        else cout << other << endl;
    }
}

int main(){
    erat();
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
