#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
int main(){
    int t;
    cin >> t;
    loop(i, t){
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> v;
        v.pb(x);
        v.pb(y);
        v.pb(z);
        sort(all(v));
        int a, b, c;
        a = v[2];
        b = v[1];
        c = v[0];
        int res = 0;
        if(a){
            a--;
            res++;
        }
        if(b){
            b--;
            res++;
        }
        if(c){
            c--;
            res++;
        }
        if(a && b){
            res++;
            a--;
            b--;
        }
        if(a && c){
            res++;
            a--;
            c--;
        }
        if(b && c){
            res++;
            b--;
            c--;
        }
        if(a&&b&&c){
            res++;
        }
        cout << res << endl;;


    }
    return 0;
}