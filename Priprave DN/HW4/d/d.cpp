/**
 * Author: MatijaL
 * Time: 2020-09-30 15:17:31
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
vector<int> primes;
const int limit = 100000;
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
        //loop(i, depth) printf("%0*d\n", len, num[i]);
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

    auto it = lower_bound(all(primes), prefix);
    int start = it - primes.begin();
    FOR(i, start, primes.size()){
        int p = primes[i];
        if(p < prefix) continue;
        if(p > nextPref-1) break;
        num[depth] = p;
        benis(depth+1);
        num[depth] = 0;
    }
}


void solve(){
    //for(auto e : primes) cout << e << endl;
    cin >> num[0];
    len = 0;
    int temp = num[0];
    while(temp){
        len++;
        temp /= 10;
    }
    benis(1);
    cout << res << endl;
    res = 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    erat();
    int t;
    cin >> t;
    while(t--)
    solve();   
}
