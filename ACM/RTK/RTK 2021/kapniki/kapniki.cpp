/**
 * Author: MatijaL
 * Time: 2021-03-27 10:23:04
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
#define DEBUG 0
void solve(){
    ll v, n;
    cin >> v >> n;
    string s;
    cin >> s;
    vector<ll> visine(n);
    loop(i, n) cin >> visine[i];

    //par<int, int> 1 - zacetek, 0-konec;
    vector<pll> kr;
    loop(i, n){
        char c = s[i];
        ll h = visine[i];
        if(c == 'M'){
            kr.pb(mp(0, 1));
            kr.pb(mp(h, 0));
        }else{
            kr.pb(mp(v-h, 1));
            kr.pb(mp(v, 0));
        }
    }

    sort(all(kr));

    ll best = inf;
    map<ll, ll> m;
    ll cur = kr[0].fs;
    ll active = 0;
    
    int i = 0;
    while(i < kr.size()){

        if(DEBUG)printf("Taking batch %lld\n", cur);
        //obracunaj vse na isti visini
        while(kr[i].fs == cur){


            pll e = kr[i];
            char c = e.sc;
            if(DEBUG)printf("%lld %lld\n", e.fs, e.sc);

            if(c == 1) active++;
            else active--;
            i++;
        }

        if(i == kr.size()) break;
        if(DEBUG)printf("active %lld\n", active);

        best = min(best, active);
        //koliko casa traja to stanje??

        m[active] += kr[i].fs - cur;         

        cur = kr[i].fs;
    }

    printf("%lld %lld\n", best, m[best]);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    while(t--) solve();   
}
