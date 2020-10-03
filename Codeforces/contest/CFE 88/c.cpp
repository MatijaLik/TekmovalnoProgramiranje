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
#define debug(x) cout << "# " << x << endl


#define limit 1000000

void solve(){
    ll h, c, t;
    cin >> h >> c >> t;
    if(h+c >= 2*t){
        cout << 2 << endl;
        return;
    }

    ll p1 = 0;
    ll p2 = limit;
    ll mid = (p1+p2)/2;

    while(p1 != p2){
        ll k = mid;
        ll exp1 = abs((k+1)*h + k*c - t*(2*k + 1)) * (2*k + 3);
        ll exp2 = abs((k+2)*h + (k+1)*c - t*(2*k + 3)) * (2*k + 1);

        //printf("l %d | d %d\n", p1, p2);
        //printf("k %d ----> %lld  %lld\n", k, exp1, exp2);


        if(exp1 > exp2){
            //naslednji k je blizje
            //pomakni se naprej

            p1 = mid+1;
            mid = (p1+p2)/2;
        }else{
            //ide nazaj
            //smo overshootali tak ko jaz tvojo mamo

            p2 = mid;
            mid = (p1+p2)/2;
        }

    }

    cout << 2*mid + 1 << endl;



}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}