/**
 * Author: MatijaL
 * Time: 2021-04-02 16:30:22
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

#define limit 1000500


#define DEBUG 0
void solve(){
    ll N, K;
    cin >> N >> K;
    ll S1, S2, X, Y, M;
    cin >> S1 >> S2 >> X >> Y >> M;
    ll A, B;
    cin >> A >> B;

    vector<ll> id[limit];

    id[S1].pb(1);
    id[S2].pb(2);

    FOR(i, 3, N){
        ll Snew = (S1*X + S2 * Y) % M;
        if(DEBUG) cout << Snew << endl;
        S1 = S2;
        S2 = Snew;

        id[Snew].pb(i);
    }

    vector<pll> elems;
    FOR(i, 0, M){
        int sz = id[i].size();
        if(sz == 0) continue;
        int start = max(sz-K, 0LL);

        FOR(j, start, sz-1){
            elems.pb(mp(id[i][j], i));

        }
    }

    sort(all(elems));

    if(DEBUG){
        for(auto e : elems){
            printf("%lld %lld\n", e.fs, e.sc);
        }
    }

    FOR(i, A, B) cout << elems[i-1].sc << " ";
    cout << endl;

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
