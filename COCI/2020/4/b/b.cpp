/**
 * Author: MatijaL
 * Time: 2021-01-16 15:03:49
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


#define limit 10000100
#define lowlimit 3200
vector<int> primes;
bool b[limit];
void erat(){
    FOR(i, 2, limit-1){
        if(b[i]==0){
            primes.pb(i);
            for(ll j = i*i; j < limit; j += i){
                b[j] = 1; 
            }
        }
    }
    return;
}
void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    for(auto e : primes){
        ll prime = e;
        if(prime > b) break;
        int ans1 = 0;
        int ans2 = 0;
        while(prime <= max(b, d)){
            int rem1 = a % prime;
            int l1 = a;
            if(rem1 != 0){
                l1 += prime-rem1;
            }

            int occ1 = (b-l1+1)/prime;
            if((b-l1+1)%prime) occ1++;
            if(l1 > b) occ1 = 0; 

            int rem2 = c % prime;
            int l2 = c;
            if(rem2 != 0){
                l2 += prime-rem2;
            }
            int occ2 = (d-l2+1)/prime;
            if((d-l2+1)%prime) occ2++;
            if(l2 > d) occ2 = 0;
            
            ans1 += occ1;
            ans2 += occ2;

            prime *= e;
        }
        
        if(ans1 > ans2){
            cout << "NE" << endl;
            return;
        }
    }
    cout << "DA" << endl;
    return; 
}

int main(){

    erat(); 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}

