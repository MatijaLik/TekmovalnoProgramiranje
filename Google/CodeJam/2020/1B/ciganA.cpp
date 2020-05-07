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
#define debug(x) cout << "# " << x << endl;

string result(ll bx, ll by, ll X, ll Y){
    string ans;
    ll xSum = 0;
    ll ySum = 0;
    for(ll i = 62; i >= 0; i--){
        if(bx & ((ll)1 << i)){
            if(xSum < abs(X)){
                xSum += ((ll)1 << i);
                if(X > 0) ans += "E";
                else ans += "W";
            }else{
                xSum -= ((ll)1 << i);
                if(X > 0) ans += "W";
                else ans += "E";
            }
        }
        if(by & ((ll)1 << i)){
            if(ySum < abs(Y)){
                ySum += ((ll)1 << i);

                if(Y > 0) ans += "N";
                else ans += "S";
            }else{
                ySum -= (1 << i);
                if(Y > 0) ans += "S";
                else ans += "N";
            }
        }
    }

    reverse(all(ans));
    if(ySum == abs(Y) and xSum == abs(X))return ans;
    else return "IMPOSSIBLEIMPOSSIBLEIMPOSSIBLEIMPOSSIBLEIMPOSSIBLEIMPOSSIBLE";
}

bool full(ll a){
    bool active = 0;
    for(ll i = 62; i >=0; i--){
        if((a)&((ll)1 << i)) active = 1;
        else if(active) return false;
    }
    return true;

}

bool disjunkt(ll a, ll b){
    return (a&b) == 0;
}


ll msb(ll n) { 
    if (n == 0) 
        return 0; 
  
    ll msb = 0; 
    while (n != 0) { 
        n = n / 2; 
        msb++; 
    } 
    return msb; 
} 


ll ngt(ll x){
    ll ans = 0;

    ans += ((ll)1 << (msb(x)));
    
    ans += (ans - x);
    return ans;
}


void solve(){
    ll X, Y;
    cin >> X >> Y;
    ll x, y;
    x = abs(X);
    y = abs(Y);


    //generirajmo vse;

    vector<ll> xs;
    vector<ll> ys;
    loop(i, (1 << 8)){
        xs.pb(i);
        ys.pb(i);
    }

    ll minl = 20;
    string best;
    for(auto e : xs){
        for(auto f : ys){
            if(full(e|f) and disjunkt(e,f)){
                string res = result(e, f, X, Y);
                //cout << e << " " << f << endl;
                if(res.size() < minl){
                    minl = res.size();
                    best = res;
                }
            }
        }
    }
    if(minl == 20) cout << "IMPOSSIBLE" << endl;
    else cout << best << endl;

}

int main(){
    int t;
    cin >> t;
    int i = 1;
    while(t--){
        printf("Case #%d: ", i++);
        solve();
    }
}