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

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int res = 0;
    int cur = 0;

    vector<pair<ll, int>> vsi;

    loop(i, n){
        int a, b;
        cin >> a >> b;
        vsi.pb(mp(a, 1));
        vsi.pb(mp(b, 0));
    }

    sort(all(vsi));


    //printf("#####\n");

    for(auto e : vsi){

        if(e.sc) cur++;
        else cur--;



        //printf("%d %d >>> %d\n", e.fs, e.sc, cur);
        res = max(cur, res);
    }

    cout << res << endl;


}