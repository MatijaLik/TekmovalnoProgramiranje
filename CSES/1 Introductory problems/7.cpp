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

ll solve(ll k){
    ll s = k*k;
    ll vsi = (s * (s-1)) / 2;

    ll bad = 0;
    if(k > 2){
        //vert
        bad = 4*(k-1)*(k-2);
    }
    //printf("k %lld | bad %lld\n", k, bad);

    return vsi - bad;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    FOR(i, 1, n){
        cout << solve(i) << endl;
    }   
}