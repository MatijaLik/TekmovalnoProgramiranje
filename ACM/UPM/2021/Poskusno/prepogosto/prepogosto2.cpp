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

    int v[N];

    v[0] = S1;
    v[1] = S2;

    FOR(i, 2, N-1){
        ll Snew = (S1*X + S2 * Y) % M;
        if(DEBUG) cout << Snew << endl;
        S1 = S2;
        S2 = Snew;

        v[i] = Snew;
    }

    
    //kolkokrat se stevilka pojavi
    int occ[limit];
    memset(occ, 0, sizeof occ);


    for(int i = N-1; i >= 0; i--){
        int val = v[i];
        if(occ[val] >= K) v[i] = -1;

        occ[val]++;
        
    }

    int cnt = 0;
    for(auto e : v){
        if(e == -1) continue;
        cnt++;
        if(A <= cnt and cnt <= B) cout << e << " ";
    }




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
