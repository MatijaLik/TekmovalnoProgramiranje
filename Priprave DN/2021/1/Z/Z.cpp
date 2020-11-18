/**
 * Author: MatijaL
 * Time: 2020-10-22 13:30:15
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

#define limit 1000010

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

ll gcd(ll a, ll b){
    if(b== 0) return a;
    else return gcd(b, a%b);
}

vector<ll> v;
int N;

void solve(){
    erat();
    //cout << "here" << endl;
    cin >> N;
    loop(i, N){
        ll a;
        cin >> a;
        v.pb(a);
    }

    ll d = v[0];
    FOR(i, 1, N-1) d = gcd(d, v[i]);

    //decompose
    map<ll, ll> cnt;
    vector<ll> div;
    ll res = 1;
    for(auto p : primes){
        while(d % p == 0){
            d /= p;
            cnt[p]++;
        }
    }

    if(d > 1) res = 2;
    for(auto e : primes) res *= (cnt[e]+1);
    cout << res << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
