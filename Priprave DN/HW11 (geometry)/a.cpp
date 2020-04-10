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

vector<pair<pll, ll>> radiators;
ll res = 0;



ll getdist(pll a, pll b){
    return (a.fs-b.fs)*(a.fs-b.fs) + (a.sc-b.sc)*(a.sc-b.sc);
}

void check(ll x, ll y){
    bool good = 0;

    for(pair<pll, ll> rad : radiators){
        if(getdist(mp(x, y), rad.fs) <= rad.sc*rad.sc){good=1;break;}
    }

    if(!good){ res += 1;}
        //printf("failde at %d %d\n", x, y);}
}

int main(){
    ll xa, xb, ya, yb;
    cin >> xa >> ya >> xb >> yb;
    int n;
    cin >> n;
    
    loop(i, n){
        ll x, y, r;
        cin >> x >> y >> r;
        radiators.pb(mp(mp(x, y), r));
    }


    FOR(x, min(xa, xb), max(xa, xb)){
        check(x, ya);
        check(x, yb);
    }

    FOR(y, min(ya, yb)+1, max(ya, yb)-1){
        check(xa, y);
        check(xb, y);
    }


    cout << res << endl;
}