/**
 * Author: MatijaL
 * Time: 2021-01-07 23:06:34
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
#define inf 2000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

void solve(){
    set<pll> ts;
    set<pll> te;
    int n;
    cin >> n;
    int nt = 0;
    int cp = 0;
    vector<pll> q;
    loop(i, n){
        int t, x;
        cin >> t >> x;
        q.pb(mp(t, x));
        if(t >= nt){
            if(t > nt){
                ts.insert(mp(nt, cp));
                te.insert(mp(t, cp));
            }
            ts.insert(mp(t, cp));
            nt = t+abs(x-cp);
            te.insert(mp(t+abs(x-cp), x));
            cp = x;
        }
    }
    ts.insert(mp(nt, cp));
    te.insert(mp(inf, cp));
    /*
    for(auto e : ts) cout << e.fs << " " << e.sc << endl;
    cout << "----------" << endl;
    for(auto e : te) cout << e.fs << " " << e.sc << endl;
    cout << "###########" << endl;
    */
    ll ans = 0;
    loop(i, n){
        pll e = q[i];
        ll x = e.sc;
        ll start = e.fs;
        ll end;
        if(i == n-1) end = inf;
        else end = q[i+1].fs;
        
        auto t = ts.upper_bound( mp(start, inf));
        t--;
        pll prev = *t;
        t = te.upper_bound(mp(start, inf));
        pll next = *t;
        end = min(end, next.fs);
        if(prev.sc == next.sc and prev.sc == x) ans++;
        if(prev.sc < next.sc){
            int a = prev.sc + (start - prev.fs);
            int b = a + (end - start);
            if(a <= x and x <= b) ans++;
        }
        if(prev.sc > next.sc){
            int a = prev.sc - (start-prev.fs);
            int b = a - (end-start);
            if(a >= x and x >= b) ans++;
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
    cin >> t;
    while(t--) solve();   
}
