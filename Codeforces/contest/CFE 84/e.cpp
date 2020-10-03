#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 200010

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        ll p[limit];
        ll c[limit];
        vector<vector<ll>> cic; 
        FOR(i, 1, N)cin >> p[i];
        FOR(i, 1, N)cin >> c[i];

        bool used[limit];
        memset(used, 0, sizeof used);
        ll l = 0;
        FOR(i, 1, N){
            if(used[i]) continue;
            ll cur = i;
            vector<ll> path;
            while(used[cur]==0){
                path.pb(cur);
                used[cur] = 1;
                cur = p[cur];
            }
            cic.pb(path);
        }
        for(auto cycle : cic){
            for(auto e: cycle){
                cout << e << " " << endl;
            }
            cout << endl;
        }
    }
}