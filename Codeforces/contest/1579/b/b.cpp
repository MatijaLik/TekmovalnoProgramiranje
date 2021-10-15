/**
 * Author: MatijaL
 * Time: 2021-09-28 16:35:02
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
    int n;
    cin >> n;
    deque<int> v(n);
    loop(i, n) cin >> v[i];
    vector<int> nav;
    vector<pll> nav2;
    FOR(L, 0, n-2){
        //find min
        int mn = inf;
        int mnid = -1;
        FOR(i, 0, v.size()-1){
            if(v[i] < mn){
                mn = v[i];

                mnid = i;
            }
        }
        
        if(mnid == 0){
            v.pop_front();
            continue;
        }

        nav.pb(mnid);
        nav2.pb(mp(L+1, n));
        loop(i, mnid){
            int e = v[0];
            v.pop_front();
            v.push_back(e);
        }
        v.pop_front();
    }
    cout << nav.size() << endl;

    loop(i, nav.size()){
        cout << nav2[i].fs << " " << n  << " " << nav[i] << endl;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
