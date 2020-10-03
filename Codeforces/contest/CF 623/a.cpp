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
        int a, b, x, y;
        cin >> x >> y >> a >> b;
        int s1 = a*y;
        int s2 = (x-a-1)*y;
        int s3 = b*x;
        int s4 = (y-b-1)*x;
        cout << max({s1,s2,s3,s4}) << endl;
    }
    return 0;
}