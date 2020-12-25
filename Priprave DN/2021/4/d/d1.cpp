/**
 * Author: MatijaL
 * Time: 2020-12-01 11:40:11
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
#define limit 100000
 
vector<ll> primes;
bool b[limit];
ll divisor[limit];
 
bool isComp[limit];
 
void erat(){
    FOR(p, 2, limit-1){
        if(isComp[p]) continue;
        primes.pb(p);
        for(ll i = p*p; i < limit; i += p) isComp[i] = true;
    }
}
 
int num[5];
int len;
int res;
void benis(int depth){
    if(depth >= len){
        //loop(i, depth) printf("%0*d ", len, num[i]);
        //printf("\n");
        res++;
        return;
    }
    int prefix = 0;
    loop(d, depth){
        prefix *= 10;
        prefix += (num[d]/(ll)pow(10, len-depth-1))%10;
    }
    int nextPref = prefix+1;
    loop(i, len-depth) prefix *= 10;
    loop(i, len-depth) nextPref *= 10;
 
    //cout << nextPref << endl;
    //cout << prefix << endl;
 
    auto it = lower_bound(all(primes),prefix);
    while(*it <= nextPref){
        int p = *it;
        num[depth] = p;
        benis(depth+1);
        num[depth] = 0;
        it++;
    }
}
 
 
int solve(int p){
    //for(auto e : primes) cout << e << endl;
    num[0] = p;
    len = 0;
    int temp = num[0];
    while(temp){
        len++;
        temp /= 10;
    }
    benis(1);
    int h = res;
    res = 0;
    return h;
    
}
   
int main(){
    erat();
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    printf("{");
    int gg = 0;
    for(auto p : primes){
        if(p < 10000) continue;
        if(p > 10030) continue;
        printf("%d %d, \n",p,solve(p));
    }
    printf("}\n");
}  
