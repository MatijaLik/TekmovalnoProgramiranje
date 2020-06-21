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
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n < 4){
        cout << "NO SOLUTION" << endl;
        return 0;
    }


    deque<int> v;
    bool tick = 0;
    int p1 = 1;
    int p2 = n;

    loop(i, n){
        if(i == n-1) v.push_front(p1);
        else if(tick) v.pb(p2--);
        else v.pb(p1++);
        tick = 1 -tick;
    }

    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
}