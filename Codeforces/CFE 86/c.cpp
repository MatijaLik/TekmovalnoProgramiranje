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

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, q;
        cin >> a >> b >> q;
        ll prod = a*b;
        ll mali = min(a, b);
        ll vlki = max(a, b);
        ll cumSum[a*b+10];

        cumSum[0] = 0;
        FOR(i, 1, prod){
            if(i%mali != (i%vlki)%mali){
                cumSum[i] = 1;
            }else{
                cumSum[i] = 0;
            }
            cumSum[i] += cumSum[i-1];
        }

        while(q--){
            ll l, r;
            cin >> l >> r;
            l--;
            ll upper, lower;

            //prvo zgoraj
            upper = (r/prod)*cumSum[prod];
            upper += cumSum[r%prod];

            lower = (l/prod)*cumSum[prod];
            lower += cumSum[l%prod];

            cout << upper - lower << " ";
        }
        cout << endl;
    }
}