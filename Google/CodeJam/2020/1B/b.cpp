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
#define limit 1e9L
#define debug(x) cout << "# " << x << endl;


string query(ll a, ll b){
    cout << a << " " << b << endl;
    string s;
    cin >> s;
    return s;
}


pll bisect(ll a, ll b, ll height, ll out){
    pll p;
    loop(i, 32){
        ll mid = (a+b)/2;
        
        p.fs = mid;
        p.sc = height;


        string s = query(p.fs, p.sc);
        if(s == "CENTER"){
            return mp(-1e10, -1e10);
        }else if( s== "HIT"){
            if(out) a = mid;
            else b = mid;
        }else if(s == "MISS"){
            if(out) b = mid;
            else a = mid;
        }else{
            exit(0);
        }
    }
    return p;
}


pll verticalBisect(ll in, ll out){
    ll a = -limit;
    ll b = limit;
    pll p;
    loop(i, 32){
        ll mid = (a+b)/2;
        
        p.fs = in;
        p.sc = mid;


        string s = query(p.fs, p.sc);
        if(s == "CENTER"){
            return mp(-1e10, -1e10);
        }else if( s== "HIT"){
            if(out) a = mid;
            else b = mid;
        }else{
            if(out) b = mid;
            else a = mid;
        }
    }
    return p;

}


void stage2(pll a, pll b){

    ll search = (a.fs+b.fs)/2;


    pll stop = mp(-1e10, -1e10); 
    pll b1 = verticalBisect(search, 1);
    if(b1 == stop) return;
    pll b2 = verticalBisect(search, 0);
    if(b2 == stop) return;


    pll res = mp(search, (b1.sc+b2.sc)/2);
    query(res.fs, res.sc);

}


void solve(){
    pll stop = mp(-1e10, -1e10); 

    

    //1. bisekcija
    pll b1 = bisect(-limit, limit, (limit/4), 1);
    if(b1 == stop) return;
    pll b2 = bisect(-limit, limit,(limit/4), 0);
    if(b2 == stop) return;

    if(b1.fs != limit){
        return stage2(b1, b2);
    }

    b1 = bisect(-limit, limit, (limit/2), 1);
    if(b1 == stop) return;
    b2 = bisect(-limit, limit, (limit/2), 0);
    if(b2 == stop) return;

    if(b1.fs != limit){
        return stage2(b1, b2);
    }



    b1 = bisect(-limit, limit, (3*limit/4), 1);
    if(b1 == stop) return;
    b2 = bisect(-limit, limit, (3*limit/4), 0);
    if(b2 == stop) return;
    return stage2(b1, b2);


}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    ll a, b;
    cin >> a >> b;
    int i = 1;
    while(t--){
        solve();
    }
}