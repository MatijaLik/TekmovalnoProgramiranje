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
#define inf 1000000000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define nlimit 10010

ll N, S;
pll slike[nlimit];


map<pair<pll, ll>, ll> memo;
set<pair<pll, ll>> memoS;

ll dp(ll i, ll top, ll rem){
    pair<pll, ll> p = mp(mp(i, top), rem);
    if(memoS.count(p)) return memo[p];
    memoS.insert(p);

    ll bot = inf;
    pll slika = slike[i];
    ll w = slika.fs;
    ll h = slika.sc;
    if(rem>=w)bot = min(bot, dp(i+1, max(top, h), rem - w));//pokoncno
    if(rem>=h)bot = min(bot, dp(i+1, max(top, w), rem - h));//posrek
    bot = min(bot, dp(i+1, 0, S));// nova vrstica
    return memo[p] = bot;
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    loop(i, N){
        ll w, h;
        cin >> w >> h;
        slike[i] = mp(w, h);
    }
    cout << dp(0, 0, s) << endl;
}