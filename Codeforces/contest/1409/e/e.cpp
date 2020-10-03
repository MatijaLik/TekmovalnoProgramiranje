/**
 * Author: MatijaL
 * Time: 2020-09-09 07:56:08
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

struct Point{
    int x, y;
    const bool operator < (const Point &other){
        return x < other.x;
    }
};
void solve(){
    int n, k;
    cin >> n >> k;
    vector<Point> v;
    int vp[n][2];
    loop(i, n) cin >> vp[i][0];
    loop(i, n) cin >> vp[i][1];
    loop(i, n) v.pb(Point{vp[i][0], vp[i][1]});

    sort(all(v));
    queue<Point> batch;
    
    //Main arrays
    int cover[n];
    int stopIndex[n];
    int si = -1;
    
    //get cover
    loop(i, n){
        /*
         * add point to queue
         * remove outdated points
         * batch.size -> cover[i]
         */
        Point np = v[i];
        batch.push(np);
        while(batch.front().x + k < np.x){
            batch.pop();
            si++;
        }
        stopIndex[i] = si;
        cover[i] = batch.size();
        
        //printf("adding %d %d -> %d, stop %d\n", np.x, np.y, cover[i], stopIndex[i]);
    }

    int mu = 0;
    int cid = -1;
    int totalMax = 0;
    loop(i, n){
        /*
         * posodobi mu do stopIndexa
         * pripisi vrednost
         */
        int stopId = stopIndex[i];
        while(cid < stopId){
            mu = max(mu, cover[++cid]);
        }
        totalMax = max(totalMax, mu+cover[i]);
    }
    printf("%d\n", totalMax);
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
