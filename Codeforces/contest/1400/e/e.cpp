/**
 * Author: MatijaL
 * Time: 2020-08-25 16:35:02
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
#define inf 1000030000
#define mod 1000000007
int n;
ll a[5100];

ll daq(ll l, ll r, ll water){
    ll ans = 0;
    ll lowest = inf;
    ll high =water; 
    //find min
    FOR(i, l, r){
        ll val = a[i];
        if(val <= water) continue;
        lowest = min(lowest, val);
        high = max(high, val);
    }
    if(high == water) return 0;//vsi so ze pod vodo
    ans++;//zbrisem vse spodnje
    //daq naprej
    bool active = 0;
    int first = -1;
    water++;
    FOR(pos, l, r){
        ll val = a[pos];
        if(val <= water and active){
            ans += daq(first, pos-1, water);
            first = -1;
            active = 0;
            continue;
        }//smo se potopili

        //smo na kopnem
        if(!active and val > water){
            first = pos;
            active = true;
        }
    }
     if(active) ans+= daq(first, r, water);
     return ans;

}
void solve(){
    memset(a, 0, sizeof a);
    cin >> n;
    loop(i, n) cin >>  a[i+1];
    ll ans = 0;
    ll water = 0;
    bool active = 0;
    int first = -1;
    
    FOR(pos, 1, n){
        ll val = a[pos];
        if(val <= water and active){
            ans+= daq(first, pos-1, water);
            first = -1;
            active = 0;
            continue;
        }//smo se potopili

        //smo na kopnem
        if(!active and val > water){
            first = pos;
            active = true;
        }
    }
    if(active) ans+= daq(first, n, water);
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
