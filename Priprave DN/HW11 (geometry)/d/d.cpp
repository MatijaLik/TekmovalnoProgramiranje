#include<vector>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pdd pair<ld, ld>
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
template <typename T, typename U>
pdd operator-(const pair<T, T> &a, const pair<U, U> &b){
    return mp(a.fs - b.fs, a. sc - b.sc);
}
 
template <typename T, typename U>
long double diss(pair<T, T> a, pair<U, U> b){
    return abs(a.fs-b.fs)*abs(a.fs-b.fs) + abs(a.sc-b.sc)*abs(a.sc-b.sc);
}
 
template <typename T, typename U>
long double dis(pair<T, T> a, pair<U, U> b){
    return sqrtl(diss(a, b));
}
 
template <typename U>
U v_prod(const pair<U,U> &l, const pair<U,U> &r){
    return l.fs*r.sc-l.sc*r.fs;
}

template <typename T, typename U>
pdd intersect(pair<T, T> a, pair<T, T> b, pair<U, U> X, pair<U, U> Y){
    //presecisce XY z ab
    //X je notranja tocka, Y pa zunanja
    long double l, d;
    l = 0;
    d = 1;
    pdd res;
    long double alpha;
    loop(i, 200){
        alpha = (l + d)/2;
        res.fs = alpha*X.fs + (1-alpha)*Y.fs;
        res.sc = alpha*X.sc + (1-alpha)*Y.sc;

        if(v_prod(res - a, b - a) > 0) d = alpha;
        else l = alpha;
    }
    return res;
}


ld area( deque<pdd> q){
    ld total = 0;
    q.push_back(q[0]);
    loop(i, q.size()-1){
        total += v_prod(q[i], q[i+1]);
    }
    return (total/2.0);
}

#define nlimit 310

ll N, K;
ll best[nlimit];
ll legacy[nlimit];


int main(){
    cin >> N >> K;
    loop(k, N){

        ld total = 0;
        bool active = 0;
        ll prev;

        deque<pdd> q;

        loop(i, K+1){

            ll temp;
            cin >> temp;
            if(active or i == 0){
                if(temp > best[i]){
                    q.push_front(mp(i,temp));
                    q.push_back(mp(i, best[i]));

                    active = 1;
                }else if(i != 0){
                    pdd inter = intersect(
                        mp(i-1, legacy[i-1]),
                        mp(i, best[i]),
                        mp(i, temp), 
                        mp(i-1, prev)
                    );
                    q.push_front(inter);
                    total += area(q);
                    
                    
                    q.clear();
                    active = 0;
                }
            }else{
                if(temp > best[i]){//pozeni
                    //daj inter pa trenutni dve
                    pdd inter = intersect(
                        mp(i-1, best[i-1]),
                        mp(i, best[i]),
                        mp(i-1, prev),
                        mp(i, temp)
                        
                    );
                    q.push_front(inter);
                    q.push_front(mp(i, temp));
                    q.push_back(mp(i, best[i]));
                    active = 1;
                }
            }


            best[i] = max(best[i], temp);
            prev = temp;
        }
        

        total += area(q);

        printf("%Lf\n", total);


        copy(begin(best), end(best), begin(legacy));
    }
    return 0;
}