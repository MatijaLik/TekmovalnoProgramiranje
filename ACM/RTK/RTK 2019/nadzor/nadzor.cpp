/**
 * Author: MatijaL
 * Time: 2021-02-19 16:34:21
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

#define limit 1000100
ll arr[limit];
ll bloki[1100];
ll dolzinaBloka = sqrt(limit);

void update(int L, int R, ll val){
     int p = L;
    //leva stran
    while(p < R and p % dolzinaBloka){
        arr[p] = min(val, arr[p]);
        p++;
    }
    //bloki
    while(p + dolzinaBloka <= R){
        bloki[p/dolzinaBloka] = min(val, bloki[p/dolzinaBloka]);
        p++;
    }

    //desno
    while(p <= R){
        arr[p] = min(val, arr[p]);
        p++;
    }
}

ll query(int i){

    ll res = arr[i];
    int blokId = i / dolzinaBloka;
    res = min(bloki[blokId], res);

    return res;
}

void solve(){
    ll n, d;
    cin >> d >> n;
    FOR(i, 0, limit-1) arr[i] = inf*1LL*inf;
    loop(i, 1100) bloki[i] = inf*1LL*inf;


    map<int, int> comp;
    vector<int> vsi;

    vector<pair<pll, ll>> v;
    loop(i, n){
        ll a,b,c;
        cin >>a >> b >> c;
        vsi.pb(a);
        vsi.pb(b);

        v.pb(mp(mp(b, a), c));
    }
    vsi.pb(0);
    vsi.pb(d);
    sort(all(vsi));
    int p = 0;
    loop(i, vsi.size()){
        if(i != 0 and vsi[i] == vsi[i-1]) continue;
        comp[vsi[i]] = p++;
    }
    
    loop(i, v.size()){
        pair<pll, ll> tup = v[i];
        ll a, b, c;
        a = tup.fs.sc;
        b = tup.fs.fs;
        c = tup.sc;

        v[i] = mp(mp(comp[b], comp[a]), c);
    }

    ll res = inf*1LL*inf;

    sort(all(v));
    update(0,0,0);
    update(1,d,res);
    for(auto e : v){
        ll a, b, c;
        a = e.fs.sc;
        b = e.fs.fs;
        c = e.sc;
    

        ll best = query(a) + c;
        update(a, b, best);
        if(b == d) res = min(res, best);

       //printf("%lld %lld %lld |-> %lld\n", a, b, c,  best);

    }

    cout << res << endl;


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
