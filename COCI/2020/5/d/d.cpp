/**
 * Author: MatijaL
 * Time: 2021-02-13 15:23:05
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
typedef long double ld;


pll operator - (pll &a, pll &b){
    return mp(a.fs-b.fs, a.sc-b.sc);
}

ll v_prod(pll a, pll b){
    return a.fs*b.sc - a.sc*b.fs; 
}




void solve(){
    ll n, h;
    cin >> n >> h;
    vector<pll> ter(n);
    loop(i, n){
        ll x, y;
        cin >> x >> y;
        ter[i] = mp(x, y);
    }
    if(n == 3){
        cout << 0 << endl;
        return;
    }

    vector<pair<ld, ld>> segs;
    vector<ld> lseg, rseg;


    //NAREDI
    vector<pll> hull;
    hull.pb(ter[0]);
    hull.pb(ter[1]);
    
    FOR(i, 2, n-2){
        //daj v ogrinjaco
        pll cur = ter[i];
        while(hull.size() > 2 and v_prod(cur - hull.end()[-2], hull.end()[-1] - hull.end()[-2]) <= 0) hull.pop_back();
        hull.pb(cur);

        if(i%2) continue;
        
        //najdi presecisce
        pll prev = hull.end()[-2];
        double dx, dy, scale;
        dx = prev.fs - cur.fs;
        dy = prev.sc - cur.sc;
        scale = ((double) h - cur.sc)/dy;
        lseg.pb(cur.fs + (dx*scale));
    }
    
    hull.clear();
    hull.pb(ter[n-1]);
    hull.pb(ter[n-2]);

    for(int i = n-3; i >= 2; i--){
        //daj v ogrinjaco
        pll cur = ter[i];
        while(hull.size() > 2 and v_prod(cur - hull.end()[-2], hull.end()[-1] - hull.end()[-2]) >= 0) hull.pop_back(); 
        hull.pb(cur);

        if(i%2) continue;

        //najdi presecisce
        pll prev = hull.end()[-2];
        double dx, dy, scale;
        dx = prev.fs - cur.fs;
        dy = prev.sc - cur.sc;
        scale = ((double) h - cur.sc)/dy;
        rseg.pb(cur.fs + (dx*scale));
    }

    

    reverse(all(rseg));
    loop(i, lseg.size()) segs.pb(mp(lseg[i], rseg[i]));
     

    const double EPS = 1e-10;

    sort(all(segs), [](const pair<ld, ld> &a, const pair<ld, ld> &b) -> bool {
            return a.sc < b.sc;
            });
  //  for(auto e : segs) printf("%Lf %Lf\n", e.fs, e.sc);


    int ans = 1;
    ld point = segs[0].sc;
    FOR(i, 1, segs.size()-1){
        if(point+EPS < segs[i].fs){
            ans++;
            point = segs[i].sc;
        }
    }


    cout << ans << endl;

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
