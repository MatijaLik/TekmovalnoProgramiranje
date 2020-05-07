#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

#define nlimit 305

template <typename T, typename U>
pair<U,U> operator-(const pair<T,T> &l, const pair<U,U> & r){
    return mp(l.fs-r.fs,l.sec-r.sec);
}

template <typename U>
ld v_prod(const pair<U,U> &l, const pair<U,U> &r){
    return l.fs*r.sc-l.sc*r.fs;
}


ld area(vector<pdd> shape){
    shape.pb(shape[0]);
    ld sum = 0;
    for(int i = 0; i < shape.size()-1; i++){
        pdd first = shape[i];
        pdd second = shape[i];
        
        sum += v_prod(first, second);
    }
    return sum/2;
}

ll coverHeights[nlimit];

ld N, K;
int main(){
    cin >> N >> K;
    ld prevArea = 0;
    loop(i, N){ 
        ld shapeArea;
        vector<pdd> shape;
        vector<pdd> shapeBuffer;

        loop(i, K+1){
            ll temp;
            cin >> temp;
            coverHeights[i] = max(coverHeights[i], temp);
            shapeBuffer.pb(mp(i, coverHeights[i]));
        }

        
        shape.pb(mp(0,0));
        shape.pb(mp(K, 0));

        reverse(all(shapeBuffer));
        for(auto e : shapeBuffer){
            shape.pb(e);
        }

        cout << "####" << endl;
        for(auto e : shape){
            cout << e.fs << " " << e.sc << endl;
        }


        shapeArea = area(shape);
        cout << shapeArea-prevArea << endl;
        prevArea = shapeArea;

    }
}