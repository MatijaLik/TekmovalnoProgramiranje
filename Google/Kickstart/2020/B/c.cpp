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
#define mod 1000000000
#define debug(x) cout << "# " << x << endl




void solve(int cs){
    ll W, H;
    W = 0;
    H = 0;
    ll n, w, s, e;
    n = 0;
    w = 0;
    s = 0;
    e = 0;


    string S;
    cin >> S;
    stack<ll> multiplier;
    multiplier.push(1);

    for(auto c : S){
        if(c < 58 and c > 47){
            ll num = (int)c - '0';
            multiplier.push((num*multiplier.top())%mod);
        }

        if(c == '(') continue;
        if(c == ')') multiplier.pop();
        else{
            if(c == 'N') n += multiplier.top();
            if(c == 'S') s += multiplier.top();
            if(c == 'W') w += multiplier.top();
            if(c == 'E') e += multiplier.top();
            n %= mod;
            s %= mod;
            w %= mod;
            e %= mod;
        }
    }

    //printf("%d %d %d %d\n", n, s, w, e);

    W += e;
    W -= w;
    W %= mod;
    while(W < 0) W += mod;
    W++;

    H += s;
    H -= n;
    H %= mod;
    while(H < 0) H += mod;
    H++;

    printf("Case #%d: %lld %lld\n", cs, W, H);
}


int main(){
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}