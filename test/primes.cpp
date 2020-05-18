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


#define limit 224500000

vector<int> primes;
bool prime[limit];
void reseto(){
    FOR(i, 2, limit){
        if(i%10000 == 0) cout << i << endl;
        if(prime[i] == false){
            if(i > 224100000){cout << i << endl; return;}
            for(ll j = (ll)i*(ll)i; j < limit; j+=i) prime[j] = 1;
        }
    }
}

int main(){ 
    reseto();
}