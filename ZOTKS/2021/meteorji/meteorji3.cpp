 
/**
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;
#define DEBUG 1

struct sort_y {
    bool operator()(const std::pll &left, const std::pll &right) {
        return left.second < right.second;
    }
};




void solve(){
    int n;
    cin >> n;

    vector<pll> points;
    vector<pair<pll, pll>> rects; //par<xInterval, yInterval>

    //coordinate compression
    map<int, int> xComp;
    map<int, int> yComp;

    set<int> xSet;
    set<int> ySet;

    loop(i, n){
        int a, b;
        cin >> a >> b;
        points.pb(mp(a, b));
    }

    int m;
    cin >> m;
    loop(i, m){
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        int cnt = 0;
        for(auto e : points){
            if(x1 <= e.fs and e.fs <= x2)
            if(y1 <= e.sc and e.sc <= y2)
            cnt++;
        }
        cout << cnt << endl;
    }  

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
