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


void solve(ll n){
    ll s = (n*(n+1)) / 2;
    if(s % 2){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<ll> v1;
    vector<ll> v2;
    ll p1, p2;
    if(n % 2){
        ll mid = (n/2)+1;
        v1.pb(mid);
        p1 = mid - 1;
        p2 = mid + 1;
    }else{
        p1 = (n/2);
        p2 = p1 + 1;
    }

    bool tick = 1;
    while(p1 != 0){
        if(n % 2){
            if(tick){
                v1.pb(p1);
                v2.pb(p2);
            }else{
                v1.pb(p2);
                v2.pb(p1);
            }
        }else{
            if(tick){
                v1.pb(p1);
                v1.pb(p2);
            }else{
                v2.pb(p2);
                v2.pb(p1);
            }
        }
        
        p1--;
        p2++;
        tick = 1-tick;
    }

    sort(all(v1));
    sort(all(v2));
    cout << v1.size() << endl;
    for(auto e : v1)cout << e << " ";
    cout << endl;
    cout << v2.size() << endl;
    for(auto e : v2)cout << e << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    solve(n);
}