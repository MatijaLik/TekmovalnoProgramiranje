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
#define inf 100000000000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 1000000010

struct Camera{
    ll a, b, c;
    Camera(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c){ }
    bool operator<(Camera other) const
    {      
        if(b == other.b && a == other.a) return c < other.c;
        if(a == other.a) return b > other.b;
        return a < other.a;
    }
};

ll d, n;
vector<Camera> v;
map<ll, ll> st;
vector<ll> zacetki;

map<ll, ll> memo;
set<ll> memoS;

ll dp(ll x, ll i){
    if(memoS.count(x))return memo[x];
    memoS.insert(x);

    
    if(x == d)return memo[x] = 0;
    vector<ll>::iterator upp = upper_bound(all(zacetki), i);
    if(upp == zacetki.end()) return inf;
    ll up = *upp;
    ll sb = st[up];


    //printf("dp %d %d\n", x, i);
    ll price = inf;
    FOR(i, sb, n-1){
        Camera cam = v[i];
        if(cam.a > x) break; 
        if(cam.b > x){
            //printf("checking cam %d\n", i);
            price = min(price, cam.c + dp(cam.b, cam.a));
        }
        
    }
    //printf("dp %d %d price: %d\n", x, i, price);
    return memo[x]=price;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> n;
    loop(q, n){
        ll a, b, c;
        cin >> a >> b >> c;
        Camera cam = Camera(a, b ,c);
        v.pb(cam);
    }

    sort(all(v));
    //cout << "######" << endl;
    ll cur = -1;
    loop(i,n){
        Camera cam = v[i];
        //printf("%d %d %d\n", cam.a, cam.b, cam.c);
        if(cur != cam.a){
            st[cam.a] = i;
            //printf("%d %d\n", cam.a, i);
            zacetki.pb(cam.a);
            cur = cam.a;
        }
    }

    cout << dp(0, -1) << endl;


}