/**
 * Author: MatijaL
 * Time: 2021-04-02 17:29:49
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

#define leto 366

void solve(){
    int n, z, k, s;
    cin >> n >> z >> k >> s;

    int d[leto];
    memset(d, 0, sizeof d);
    int ogd[leto];
    memset(ogd, 0, sizeof ogd);

    loop(i, n){
        int a, b;
        cin >> a >> b;
        d[a] = b;
        ogd[a] = b;
    }

    int init = z;
    FOR(i, 1, leto-1){
        int res = max(0, d[i] - init);
        init -= d[i] - res;
        d[i] = res;
    }

    //unici tisti presezek
    z -= init;

    int cum[leto];
    memset(cum, 0, sizeof cum);
    cum[1] = d[1];
    FOR(i, 2, leto-1) cum[i] = cum[i-1] + d[i];

    

    //preveri, ali je mogoce
    FOR(i, 1, leto-1) if(cum[i] > k*(i-1)){
        cout << -1 << endl;
        return;
    }

    int prod[leto];
    memset(prod, 0, sizeof prod);

    //kolko vsak dan proizvedemo
    FOR(i, 2, leto-1){
        
        int rem = d[i];
        int j = i-1;

        while(rem > 0){
            int increment = min(k-prod[j], rem);
            rem -= increment;
            prod[j] += increment;
            j--;
        }
    }

    //debug
    //loop(i, leto) cout << prod[i] << " ";
    //cout << endl;

    int skladisce = z;
    int cost = 0;

    FOR(dan, 1, leto-1){
        cost += skladisce*s;
        skladisce -= ogd[dan];
        skladisce += prod[dan];
    }

    cout << cost << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--) solve();   
}
