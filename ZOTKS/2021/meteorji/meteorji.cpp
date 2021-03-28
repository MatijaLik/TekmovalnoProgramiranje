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
        xSet.insert(a);
        ySet.insert(b);

        points.pb(mp(a, b));
    }

    int m;
    cin >> m;
    loop(i, m){
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        xSet.insert(x1);
        xSet.insert(x2);
        ySet.insert(y1);
        ySet.insert(y2);

        rects.pb(mp(mp(x1, x2), mp(y1, y2)));
    }

    //NAREDI BIJEKCIJO
    int cnt = 0;
    for(auto e : xSet){
        xComp[e] = cnt++;
    }

    cnt = 0;
    for(auto e : ySet){
        yComp[e] = cnt++;
    }

    //popravi tocke in pravokotnike
    loop(i, n){
        points[i].fs = xComp[points[i].fs];
        points[i].sc = yComp[points[i].sc];
    }

    loop(i, m){
        rects[i].fs.fs = xComp[rects[i].fs.fs];
        rects[i].fs.sc = xComp[rects[i].fs.sc];
        rects[i].sc.fs = yComp[rects[i].sc.fs];
        rects[i].sc.sc = yComp[rects[i].sc.sc];
    }

    if(DEBUG){
        printf("compressing...\n");
        for(auto e : points) printf("%lld %lld\n", e.fs, e.sc);
        for(auto e : rects) printf("%lld-%lld %lld-%lld\n",
         e.fs.fs, e.fs.sc, e.sc.fs, e.sc.sc);
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
