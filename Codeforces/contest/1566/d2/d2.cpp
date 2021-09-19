/**
 * Author: MatijaL
 * Time: 2021-09-12 16:35:12
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n*m);
    loop(i, n*m) cin >> v[i];
    vector<int> srtd = v;
    sort(all(srtd));
    ll ans = 0;
    multiset<int> rows[n];
    for(auto e : v){
        //najdi razpon
        int l = upper_bound(all(srtd), e-1) - srtd.begin();
        int r = upper_bound(all(srtd), e) - 1 -srtd.begin();
        int ll = l / m;
        int rr = r / m;
        
       // printf("element %d| %d - %d| rows %d - %d\n", e, l, r, ll, rr);

        //na zacetek - kolko jih precka
        auto it = rows[ll].lower_bound(e);
        int sCost = rows[ll].size() - distance(it, rows[ll].end());

        //na konec - kolko drugih bo preckalo
        int eCost;
        int right = m - (r%m) - 1;
        it = rows[rr].upper_bound(e);
        eCost = right - distance(it, rows[rr].end());
        
        //na start
        if(rows[ll].count(e) < m - (l%m)){
            rows[ll].insert(e);
            ans += sCost;
            continue;
        }
        bool done = false;
        //probaj v sredino
        for(int i = ll+1; i <= rr-1; i++){
            if(rows[i].size() < m){
                rows[i].insert(e);
               // printf("inserting in %d\n", i);
                done = true;
                break;
            }
        }

        if(done) continue;
        //na konec
        rows[rr].insert(e);

                

        
    }
    cout << ans << endl;
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
