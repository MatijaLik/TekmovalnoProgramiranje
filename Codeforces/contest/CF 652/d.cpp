#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl

#define limit 2000100

ll active[limit];
ll total[limit];

void solve(){
    ll n;
    cin >> n;
    cout << (4*(
        (total[n])% mod)
    )
     % mod << endl;

    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    active[1] = 0;
    active[2] = 0;
    active[3] = 1;

    total[1] = 0;
    total[2] = 0;
    total[3] = 1;
    

    FOR(i, 3, limit-50){

        active[i+1] = (active[i+1] + active[i])%mod;// novo zraste iz sredine

        //aktualno bo vsaki 1/3 generaciji, zacensi z i+1
        total[i+1] = (total[i+1] + active[i]) % mod;



        active[i+2] = (active[i+2] + 2*active[i])%mod; // iz strani

        //aktualni bosta vsaki 1/3 generaciji, takoj ko zrasteta
        total[i+2] = (total[i+2] + 2*active[i]) % mod;
        

        //prenesi naporej
        //stiridnevna perioda
        total[i+3] = (total[i+3] + total[i])%mod;
    }

    /*
    FOR(i, 3, 7){
        printf("n %d | active %d | total %d\n", i, active[i], total[i]);
    }*/

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}