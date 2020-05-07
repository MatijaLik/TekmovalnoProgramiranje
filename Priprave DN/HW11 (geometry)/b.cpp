#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
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

const double EPS = 1e-12;
const ll shift = 1e9 + 10;
pll start = mp(0, 0);
vector<pll> ab;
vector<pll> prvilik;
vector<pll> drugilik;
vector<pll> hull;
ll N, M;
set<pll> ASet;

template <typename T, typename U>
pair<U, U> operator-(const pair<T, T> &a, const pair<U, U> &b){
    return mp(a.fs - b.fs, a. sc - b.sc);
}

template <typename T>
int v_prod(const pair<T, T> &a, const pair<T, T> &b){
    if(a.fs*b.sc == b.fs*a.sc) return 0;
    else if(a.fs*b.sc > b.fs*a.sc) return 1;
    return -1;
}

ull len(pll a){
    ull c = a.fs;
    ull d = a.sc;
    return c*c + d*d;
}

bool po_kotu(pll a, pll b){
    if(v_prod(a-start, b - start) == 0) return len(a-start) < len(b-start);
    return v_prod(a-start, b - start) > 0;
}

void pp(pll a){
    cout << a.fs-shift << " " << a.sc-shift << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool error = 0;
    cin >> N;
    loop(i, N){
        ll a, b;
        cin >> a >> b;
        a += shift;
        b += shift;
        
        ab.pb(mp(a, b));
        prvilik.pb(mp(a,b));
        ASet.insert(mp(a, b));
    }

    cin >> M;
    loop(i, M){
        ll a, b;
        cin >> a >> b;
        a += shift;
        b += shift;

        drugilik.pb(mp(a,b));
        if(ASet.count(mp(a, b))) error = 1;
        ab.pb(mp(a, b));
    }

    if(error){
        cout << "NO" << endl;
        return 0;
    }
    //cout << start.first << " " << start.second << endl;

    sort(all(prvilik), po_kotu);
    start = prvilik[0];
    sort(ab.begin(), ab.end(), po_kotu);

    /*
    cout << "SORTED" << endl;
    for(auto p : ab){
        cout << (ll)p.fs - shift << " " << (ll)p.sc  - shift<< endl;
    }*/


    hull.pb(ab[0]);
    hull.pb(ab[1]);
    FOR(i, 2, ab.size()-1){
        pll candid = ab[i];        
        while(hull.size()>=2 && v_prod(candid - hull.end()[-2], candid - hull.end()[-1]) == -1) {
            hull.pop_back();
        }

        hull.pb(candid);
    }

    /*
    cout << "HULL" << endl;
    for(auto p : hull){
        cout << (ll)p.fs - shift << " " << (ll)p.sc  - shift<< endl;
    }*/

    //preveri za zadnjo stranico
    for(pll p : drugilik){
        if(v_prod(p - hull.end()[-1], p - hull[0]) == 0){
            cout << "NO" << endl;
            return 0;
        }
    }


    for(auto p : hull){
        if(ASet.count(p)) continue;
        else{
            //printf("Error at %d %d\n", p.fs, p.sc);
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}