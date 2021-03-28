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
 
#define rlimit 1010



ll ms[rlimit];

 
int main(){
    ms[1] = 1;
    FOR(i,2, rlimit-1){
        ms[i] = ms[i-1] + 4*i - 4;
    }
    ll t;
    cin >> t;
    set<pll> visited;
    ll cnt = 0;
    queue<pair<pll, ll>> q;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        q.push(mp(mp(a,b), c));
    }
    while(!q.empty()){
        pair<pll, ll> p = q.front();
        q.pop();
        
        ll x = p.fs.fs;
        ll y = p.fs.sc;
        ll r = p.sc;
        //printf("%d %d %d\n", x, y, r);
        if(visited.count(mp(x, y))) continue;
        visited.insert(mp(x, y));
        cnt++;
        if(r==0) continue;
        q.push(mp(mp(x+1, y), r-1));
        q.push(mp(mp(x, y+1), r-1));
        q.push(mp(mp(x-1, y), r-1));
        q.push(mp(mp(x, y-1), r-1));
    }
    //cout << ms[100] << endl;
    cout << cnt << endl;
}