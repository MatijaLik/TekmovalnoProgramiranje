#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


#define limit 100010

ll N;
ll known;
ll ptn[2*limit];

vector<ll> primes;
bool b[limit];
ll divisor[limit];
void erat(){
    FOR(i, 2, limit){
        if(b[i]==0){
            primes.pb(i);
            divisor[i]=i;
            for(ll j = i*i; j < limit; j += i){
                b[j] = 1;
                divisor[j]=i;
            } 
        }
    }
    return;
}

int main(){
    //erat();
    cin >> N;
    ll p = 1;
    ll first;
    loop(i, N){
        ll temp;
        cin >> temp;
        if(i==0){
            first = temp;
            continue;
        }
        ptn[i] += temp;
        ll num = i;
        while(num + i < N+2){
            num += i;
            ptn[num] -= ptn[i];
        }
        //printf("p is %d, num is %d\n", p, ptn[i]);
        //printf("increment by %d\n", ptn[i]);
        known += ptn[i];
        p++;
    }
    printf("%d %d\n", first, first-known);
    FOR(i, 1, N+1)if(ptn[i]>0) printf("%d %d\n", i, ptn[i]);
    return 0;
}