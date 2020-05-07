#include<vector>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<long double, long double>
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

const long double EPS  = 1e-12;

long double X0, Y0, X1, Y1;
long double  v, t;
long double  vx, vy;
long double  wx, wy;

template <typename T, typename U>
pair<U, U> operator-(const pair<T, T> &a, const pair<U, U> &b){
    return mp(a.fs - b.fs, a. sc - b.sc);
}

template <typename T, typename U>
pair<U, U> operator+(const pair<T, T> &a, const pair<U, U> &b){
    return mp(a.fs + b.fs, a. sc + b.sc);
}

template <typename T, typename U>
long double diss(pair<T, T> a, pair<U, U> b){
    return abs(a.fs-b.fs)*abs(a.fs-b.fs) + abs(a.sc-b.sc)*abs(a.sc-b.sc);
}

template <typename T, typename U>
long double dis(pair<T, T> a, pair<U, U> b){
    return sqrtl(diss(a, b));
}

template <typename T, typename U>
bool insideCircle(pair<T, T> a, pair<U, U> S, ll r){
    return diss(a, S) <= r*r;
}

template <typename T, typename U>
bool onCircle(pair<T, T> a, pair<U, U> S, ll r){
    return abs(diss(a, S) - r*r) < EPS;
}

template <typename T, typename U>
long double intersect(pair<T, T> a, pair<T, T> b, pair<U, U> S, ll r){
    long double l, d;
    l = 0;
    d = 1;
    pdd res;
    long double alpha;
    loop(i, 200){
        alpha = (l + d)/2;
        res.fs = alpha*a.fs + (1-alpha)*b.fs;
        res.sc = alpha*a.sc + (1-alpha)*b.sc;
        if(insideCircle(res, S, r))d = alpha;
        else l = alpha;
    }
    return alpha;
}



int main(){
    cin >> X0 >> Y0 >> X1 >> Y1;
    cin >> v >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;

    //prestavimo Start v 0,0

    pdd Start = mp(0, 0);
    pdd X = mp(X1 - X0, Y1 - Y0); //nas cilj

    if(Start==X){
        cout << 0 << endl;
        return 0;
    }

    //##############################
    //preverimo, ce se da prvic priti do cilja

    //naredimo srediscni razteg kroga v tocki vx, vy z radijem v
    //skozi izhodisce (0,0)
    //novi radij = t * v
    // sredisce bo na k*(vx, vy)
    // el krog prestavimo za vektor (x0, y0)

    long double  Ra = t*v;
    long double  Sx = t*vx;
    long double  Sy = t*vy;


    pll S = mp(Sx, Sy);

    //printf("First circle x %lld y %lld radius %lld \n", Sx, Sy, Ra);

    //preverimo, ali je cilj notri
    
    if(insideCircle(X, S, Ra)){
        pdd adjustedX;
        adjustedX.fs = 10000*X.fs;
        adjustedX.sc = 10000*X.sc;
        long double alpha = 1-intersect(Start, adjustedX, mp(vx, vy), v);//kje seka mali krog
        alpha *= 10000;
        //printf("intersection at %f %f\n", res.fs, res.sc);
        //printf("Ratio is %.18f\n", ratio);
        printf("%.18Lf\n", 1/alpha);
        //cout << ratio << endl;
        return 0;
    }


    //##############################
    //Iskanje se nadaljuje

    //Naj bo S sredisce prvega kroga
    //X nas cilj
    //Q sredisce drugega kroga prestavljenega na X0

    //1. definirajmo Q
    //naj bo Q0 prvotno sredisce
    //vektor SQ = -(StartQ0)

    pll StartQ0 = mp(wx, wy) - Start;

    pll Q = X - StartQ0;

    //printf("Second circle is on %d %d\n", Q.fs, Q.sc); 


    long double l = 0;
    long double r = 1e18; 
    
    long double k;
    loop(i, 200){
        k = (l+r)/2;
        //cout << k << endl;
        long double dab = Ra + v*k;

        pdd newPos = mp(X.fs + k*(Q.fs - X.fs), X.sc + k*(Q.sc - X.sc));//kje se drugi krog nahaja po casu k

        long double len2 = diss(newPos, S);

        //printf("DAB is %f and LEN is %f\n", dab, len);

        if(dab*dab <= len2) l = k;
        else r = k;
    }

    //printf("K is equal to %f\n", k);
    printf("%.18Lf\n", k+t);
    //cout << k+t << endl;

    /*
    //daljica XS
    //A presecisce z drugim krogom
    pdd Ai = intersect(X, S, Q, v);

    //B presecisce
    pdd Bi = intersect(S, X, S, Ra);

    printf("Ai at %.12f %.12f\n", Ai.fs, Ai.sc);
    printf("Bi at %.12f %.12f\n", Bi.fs, Bi.sc);
    */


}