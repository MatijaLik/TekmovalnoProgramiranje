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
#define debug(x) cout << "# " << x << endl;


#define nlimit 1000010

ll vrednost[nlimit];

ll psj[nlimit];
ll psm[nlimit];


ll N, K, X;
ll janko[nlimit];
ll metka[nlimit];

map<pair<pll, pll>, ll> memo;
set<pair<pll, pll>> memoS;

ll dp(ll i, ll j, ll m, ll k){
    pair<pll, pll> p = mp(mp(i, j),mp(m, k));
    if(memoS.count(p)) return memo[p];
    memoS.insert(p);
    if(i>N){
        if(j <= 0 and m <= 0 and k == 0) return memo[p] =  0;
        else return memo[p] = -inf;
    }
    //ll rem = N-i+1;
    //if(rem < k) return memo[p] = -inf;
    //if(k < psj[i])return memo[p] = -inf;
    //if(k < psm[i])return memo[p] = -inf;
    //printf("dp %d %d %d %d\n", i, j, m, k);

    //vzemi
    ll bj, bm;
    bm = 0;
    bj = 0;
    if(janko[i]==1) bj = 1;
    if(metka[i]==1) bm = 1;
    return memo[p] = max(
        vrednost[i] + dp(i+1, j-bj, m-bm, k-1),
        dp(i+1, j, m, k)
    );

    
}


int main(){
    cin >> N >> K >> X;
    FOR(i, 1, N){
        cin >> vrednost[i];
    }
    ll j, m;
    cin >> j;
    loop(i, j){
        ll temp;
        cin >> temp;
        janko[temp]=1;
    }
    cin >> m;
    loop(i, m){
        ll temp;
        cin >> temp;
        metka[temp]=1;
    }

    //partial sums
    /*
    ll sumj = 0;
    ll summ = 0;
    for(ll i = nlimit-1; i > 0; i--){
        if(janko[i])sumj++;
        if(metka[i])summ++;
        psj[i]=sumj;
        psm[i]=summ;
    }*/
    /*
    FOR(i, 1 , N){
        cout << psj[i] << " " << psm[i] << endl;
    }*/
    cout << dp(1, X, X, K) << endl;
}