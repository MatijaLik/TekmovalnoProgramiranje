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

#define limit 100010

void solve(int cs){
    ll result = 0;
    int n;
    cin >> n;
    vector<int> v(n);

    int shift = 0;

    loop(i, n){
        cin >> v[i];
        shift += abs(v[i]);
    }

    vector<int> cnt(2*shift + 1);

    ll pref = 0;
    cnt[shift]++;

    loop(i, n){
        pref += v[i];
        for(int j = 0; j*j <= shift + pref; j++){
            result += cnt[shift + pref - j*j]; 
        }
        cnt[shift + pref]++;
    }


    printf("Case #%d: %lld\n", cs, result);
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}