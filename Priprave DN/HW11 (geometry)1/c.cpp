#include<vector>
#include<math.h>
#include<algorithm>
#include<iostream>
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
#define debug(x) cout << "# " << x << endl;

ll X0, Y0, X1, Y1;
ll v, t;
ll vx, vy;
ll wx, wy;

ll diss(pll a, pll b){
    return abs(a.fs-b.fs)*abs(a.fs-b.fs) + abs(a.sc-b.sc)*abs(a.sc-b.sc);
}

double dis(pll a, pll b){
    return sqrt(diss(a, b));
}

bool insideCircle(pll a, pll S, ll r){
    return diss(a, S) <= r*r;
}

pdd

int main(){
    cin >> X0 >> Y0 >> X1 >> Y1;
    cin >> v >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;


    pll X = mp(X1, Y1); //nas cilj

    //##############################
    //preverimo, ce se da prvic priti do cilja

    //naredimo srediscni razteg kroga v tocki vx, vy z radijem v
    //skozi izhodisce (0,0)
    //novi radij = t * v
    // sredisce bo na k*(vx, vy)
    // el krog prestavimo za vektor (x0, y0)

    ll Ra = t*v;
    ll Sx = t*vx;
    ll Sy = t*vy;

    Sx += X0;
    Sy += Y0;

    pll S = mp(Sx, Sy);

    printf("First circle x %lld y %lld radius  %lld \n", Sx, Sy, Ra);

    //preverimo, ali je cilj notri
    
    if(insideCircle(X, S, Ra)){

    }

}