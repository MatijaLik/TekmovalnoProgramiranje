#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


#define limit 1000010
ll prisotni[limit];
ll mafija[limit];//kateri mafiji pripada
ll nevarnost[limit];//koliko pistol kaze v njega
ll pointing[limit][2];//kam kaze s pistolom

int main(){

    ll N, M;
    cin >> N >> M;

    

    loop(q, N+10) prisotni[q] = 1;
    memset(nevarnost, 0, sizeof nevarnost);

    FOR(q, 1, N){
        ll t, a, b;
        cin >> t >> a >> b;
        mafija[q] = t;
        pointing[q][0] = a;
        pointing[q][1] = b;
    }

    //asertiraj nevarnost
    FOR(q, 1, N){
        loop(e, 2){
            ll zrtev = pointing[q][e];
            if(mafija[zrtev]!=mafija[q]){
                nevarnost[zrtev]++;
            }
        }
    }
    
    queue<ll> leaving;
    FOR(q, 1, N){
        if(nevarnost[q]==0 and prisotni[q]==1) {
            leaving.push(q);
            prisotni[q] = 0;
        }
    }
    while(!leaving.empty()){
        if(leaving.size()>limit) break;
        ll mafioso = leaving.front();
        leaving.pop();
        if(mafioso <= 0) continue;
        loop(e, 2){
            ll zrtev = pointing[mafioso][e];
            if(mafija[zrtev]!=mafija[mafioso]){
                nevarnost[zrtev]--;
                if(nevarnost[zrtev]<=0 and prisotni[zrtev]==1){
                    prisotni[zrtev] = 0;
                    leaving.push(zrtev);
                }
            }
        }
    }
    

    
    FOR(w, 1, N){
        if(w < 0 or w >= limit) break;
        if(prisotni[w]) printf("%lld\n", w);
    }
    return 0;
}