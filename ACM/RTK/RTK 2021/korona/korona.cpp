/**
 * Author: MatijaL
 * Time: 2021-03-27 14:02:47
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

#define limit 200500
#define DEBUG 1
int N, K, L;
int urnik[limit][7];

ll simulate(int prviClovek, int prviDan){
    int mrtvi = 0;

    bool mrtev[N];
    loop(i, N) mrtev[i] = false;

    priority_queue<pll> q;//<dan, clovek>
    q.push(mp(-prviDan, prviClovek));


    while(!q.empty()){

        auto e = q.top();
        q.pop();


        int oseba = e.sc;

        int dan = -e.fs;
        
        //if(DEBUG) printf("dan %d oseba %d\n", dan, oseba);
        if(mrtev[oseba]) continue;
        
        //prvi dan okuzevanja
        int i = dan + K;
        FOR(f, 1, L){
            //okuzuje L dni
            int zrtev = urnik[oseba][i%7];
            //printf("yrvet %d\n", zrtev);
            if(!mrtev[zrtev]){
                
                //printf("pushing %d\n", i);
                q.push(mp(-i, zrtev));
            }
            i++;
        }

        mrtev[oseba] = true;
        mrtvi++;
    }

    //printf("mrtvi %d\n", mrtvi);

    return mrtvi;
}

void solve(){
    cin >> N >> K >> L;
    loop(i, N){
        loop(j, 7) cin >> urnik[i][j];
    }

    map<int, pll> ex;
    map<int, int> m;
    int best = inf;


    //simulate(1, 5);
    //return;

    FOR(d, 0, 6){
        FOR(p, 0, N-1){
            int res = N -simulate(p, d);
            //printf("res %d\n", res);
            best = min(best, res);
            m[res]++;
            ex[res] = mp(p, d);

            //if(res == 0) printf("%d %d\n", p, d);
        }
    }

    printf("%d %d %d %d\n", ex[best].fs,ex[best].sc, best, m[best]);

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
