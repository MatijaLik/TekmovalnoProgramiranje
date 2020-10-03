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
#define inf 1000000000
#define mod 1000000007
  ll p, f;
    ll cnts, cntw;
    ll s, w;
ll test(ll sp){
    ll me = p;
    ll him = f;

    ll swords = cnts -sp;
    ll waraxes = cntw;


    ll ans = 0;
    ll spw = sp*s;
    if(spw > p) return -1;
    me -= spw;
    ans += sp;
    ll wpamnt =min( me / w, waraxes);
    ans += wpamnt;
    waraxes -= wpamnt;
    printf("%lld %lld %lld\n", ans, waraxes, swords);

    //se njemu nalozi
    if(s < w){
        ll swordsforhim = min(swordsforhim, him / s);
        ans += swordsforhim;
        him -= swordsforhim*s;

        ll warforhim = min(waraxes, him / w);
        ans += warforhim;
        
    }else{
        ll warforhim = min(waraxes, him / w);
        ans += warforhim;
        him -= warforhim*w;
        ll swordsforhim = min(swords, him / s);
        ans += swordsforhim;
    }
    return ans;
    
}

void solve(){
    cin >> p >> f;
    cin >> cnts >> cntw;
    cin >> s >> w;


    ll ans = 0; 
    FOR(i, 0, cnts){
        ans = max(ans, test(i));
    }
    printf("%lld\n", ans);

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
