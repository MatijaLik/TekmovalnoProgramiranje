/**
 * Author: MatijaL
 * Time: 2021-04-15 16:04:52
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
 
#define DEBUG 0
#define limit 50000
 
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
 
 
void solve(){
    int lim = 20;
    
    ll s=0, d=0, p=0;
    int dlen = 0, plen = 0;
    string str;
    cin >> str;
    int state = 0;

    if(str.size() == 0) return;
    for(auto e : str){
        if(e == '.'){
            state++;
        }else if(e == '(' or e == ')'){
            state++;
        }else{
            if(state==0){
                s*= 10;
                s += e-'0';
            }else if(state == 1){
                d *= 10;
                d += e-'0';
                dlen++;
            }else if(state == 2){
                p *= 10;
                p += e-'0';
                plen++;
            }
        }
    }
 
    ll x1 = s;
    loop(i, dlen) x1 *= 10;
    x1 += d;
 
    ll x2 = x1;
    loop(i, plen) x2 *= 10;
    x2 += p;
 
    if(DEBUG)cout << x1 << " " << x2 << endl;
    if(DEBUG)cout << "dlen" << dlen << " plen" << plen << endl;
 
    ll ex1 = 1;
    ll ex2 = 1;
 
    loop(i, dlen) ex1 *= 10;
 
    loop(i, dlen) ex2 *= 10;
    loop(i, plen) ex2 *= 10;
 
    ll b = ex2-ex1;
    ll a = x2-x1;
    //a * x = b
 
    if(plen == 0){
        a = x1;
        b = ex1;
    }
 
    if(DEBUG)cout << "fraction " << a << "/" << b << endl;
    
    for(auto e : primes){
        if(b == 1) break;
        while(a%e == 0 and b % e == 0){
            a /= e;
            b /= e;
        }
    }
 
    if(a%b == 0){
        a /= b;
        b = 1;
    }
    
    if(b == 1) cout << a << endl;
    else cout << a << "/" << b << endl;
 
    if(DEBUG)cout << "////" << endl;
 
}
 
int main(){
    erat();
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    while(cin.good())solve();   
}