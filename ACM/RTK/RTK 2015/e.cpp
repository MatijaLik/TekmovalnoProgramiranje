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

#define limit 1005

ll memo[limit][limit];

ll N, K;

int niz[limit];

ll cumSum0[limit];
ll cumSum1[limit];

ll gv(ll f, ll s){
    ll z = cumSum0[s] - cumSum0[f-1];
    ll o = cumSum1[s] - cumSum1[f-1];
    return min(z, o);
}

ll dp(ll m, ll t){
    if(memo[m][t]!=-1) return memo[m][t];
    if(t > m) return memo[m][t] = inf;
    if(t == 1) return memo[m][t] = gv(1, m);
    ll opt = inf;
    FOR(r, 1, m-1){
        ll res = dp(r, t-1)+gv(r+1, m);
        if(res < opt) opt = res;
    }
    return memo[m][t] = opt;

}


int main(){
    cin >> N >> K;
    string s;
    cin >> s;
    FOR(i, 1, N){
        char c = s[i-1];
        if(c == '1') niz[i] = 1;
        else niz[i] = 0;
    }
    
    //get cum cum
    ll sum0 = 0;
    ll sum1 = 0;
    FOR(i, 1, N){
        if(niz[i]) sum1++;
        else sum0++;
        cumSum0[i] = sum0;
        cumSum1[i] = sum1;
    }


    //cout << gv(1, 4) << endl;
    //cout << gv(7, 9) << endl;
    //pripravi za dp
    loop(i, limit)loop(j, limit) memo[i][j]=-1;
    cout << dp(N, K) << endl;
}