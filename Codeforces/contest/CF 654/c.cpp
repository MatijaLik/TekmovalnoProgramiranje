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


bool check(ll v, ll c, ll n, ll m){
    if(v > c){
        c -= m;
        if(c < 0) return 0;

        if(n <= v-c) return 1;
        else return 0;
    }else{
        v -= m;
        if(v < 0) return 0;
        if(n <= c-v+1 and n <= c) return 1;
        else return 0;
    }
}

void solve(){
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if(check(a, b, n, m)) cout << "Yes" << endl;
    else cout << "No" << endl; 
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)solve(); 
}