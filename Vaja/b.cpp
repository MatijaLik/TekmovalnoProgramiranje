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

#include <chrono>

using namespace std::chrono;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    milliseconds ms = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch());
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    srand(ms.count());
    while(true){
        //zgeneriraj 12 parov
        vector<pll> v;
        loop(i, 12){
            int a = rand() % 4;
            int b = rand() % 4;
            v.pb(mp(a, b));
        }

        bool gremoNanovo = 0;

        //poglej ce obstaja podmnozica 4, da je produkt popolna cetrata potenca
        for(ll mask = 0; mask < (1<<12); mask++){
            if(__builtin_popcount(mask)!= 4) continue;
            int a = 0;
            int b = 0;
            loop(i, 12){
                if(mask & (1LL<<i)){
                    a += v[i].fs;
                    b += v[i].sc;
                }
            }

            if(a%4 == 0 and b%4 == 0){
                gremoNanovo = 1;
                break;
            }
        }

        if(gremoNanovo) continue;
        sort(all(v));
        for(auto e : v){
            cout << e.fs << " " << e.sc << endl;
        }
        return 0;
    }    
}