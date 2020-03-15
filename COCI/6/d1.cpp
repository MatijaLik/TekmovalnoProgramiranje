#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>

using namespace std;
#include <format>
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


int grid[510][510];
int og[510][510];
int N, M;

int main(){
    cin >> N >> M;
    vector<pii> v;
    loop(i, N) loop(j, M){
        char c;
        cin >> c;
        int h = (int)c - '0';
        grid[i][j] = h;
        if(h==1 and (i!= 0 or j != 0));
        v.pb(mp(i, j));
    }
    vector <string> ans;
    if(N > M){
        FOR(i, 2, N+1){
            ans.pb(format("%d %d, DESNO", i, 1));
        }
    }else{
        FOR(i, 2, M+1){
            ans.pb(format("%d %d, DESNO", 1, i));
        }
    }



    cout << ans.size() << endl;
    for(auto s: ans){
        cout << s << endl;
    }
}