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


void solve(){
    multiset<int> ms;
    set<pair<int, int>> s;
    int x, n;
    cin >> x >> n;

    s.insert(mp(0, x));
    ms.insert(x);

    loop(i, n){
        int q;
        cin >> q;
        
        auto it = s.upper_bound(mp(q, inf));
        it--;
        pair<int, int> e = *it;
        s.erase(it);
        ms.erase(ms.find(e.sc - e.fs));

        s.insert(mp(e.fs, q));
        ms.insert(q - e.fs);

        s.insert(mp(q, e.sc));
        ms.insert(e.sc - q);

        cout << *ms.rbegin() << " ";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}