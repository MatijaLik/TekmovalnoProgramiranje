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
    string s;
    cin >> s;

    int maxDepth = 0;
    int depth = 0;
    for(auto c : s){
        if(c == '+') depth--;
        else depth++;
        maxDepth = max(maxDepth, depth);
    }

    int x = maxDepth + 1;
    ll ans = 0;
    ll lowestSoFar = 0;
    ll curDepth = 0;
    for(auto c : s){
        ans += x - lowestSoFar;

        if(c == '+') curDepth--;
        else curDepth++;

        lowestSoFar = max(lowestSoFar, curDepth);
    }

    cout << ans << endl;

    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}