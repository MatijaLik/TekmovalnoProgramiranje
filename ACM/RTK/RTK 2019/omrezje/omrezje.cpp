/**
 * Author: MatijaL
 * Time: 2021-02-19 11:18:17
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

void solve(){
    int k;
    cin >> k;
    //vektor vseh intervalov
    vector<pair<ll, pll>> v;//y, l, r

    while(k--){
        ll x, y, r;
        cin >> x >> y >> r;

        //sredina pa gor
        FOR(i, 0, r){
            v.pb(mp(y+i, mp(x-r+i, x+r-i)));
        }

        //dol
        FOR(i, 1, r){
            v.pb(mp(y-i, mp(x-r+i, x+r-i))); 
        }
    }

    sort(all(v));
    ll ans = 0;
    ll cy = -inf;
    ll cr = -inf;

    for(auto e : v){
       // printf("%lld | %lld %lld\n", e.fs, e.sc.fs, e.sc.sc);
        ll y, l, r;
        y = e.fs;
        l = e.sc.fs;
        r = e.sc.sc;
       
        if(y != cy or cr < l){
            //stej v celoti
            ans += r-l+1;
        }else if(y == cy and l <= cr){

            if(r <= cr) continue;
           // printf("presek\n");
            ans += r-l+1;
            //odstej presek
            ans -= cr-l+1;
        }else assert(false);

        if(cr < r) cr = r; 
        if(y != cy){
            cy = y;
            cr = r;
          //  cout << ans << endl;
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
