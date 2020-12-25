/**
 * Author: MatijaL
 * Time: 2020-11-20 15:58:28
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

ll gcd(ll a, ll b){
    if ( b== 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}


void solve(){
    FOR(a, 1, 300){
        FOR(b, a, 300){
            FOR(c, b, 300){

                //x + y + z = u
                ll x = lcm(a, b);
                ll y = lcm(a, c);
                ll z = lcm(b, c);

                ll u = lcm(x, z);
                ll v = gcd(a, gcd(b, c));

                if(x + y + z == u + v)
                printf("%d %d %d\n", a, b, c);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();   
}
