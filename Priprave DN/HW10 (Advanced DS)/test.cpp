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
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define qlimit 50000
#define nlimit 100000

int main(){
    srand (time(NULL));
    freopen("input.txt", "w", stdout);
    cout << nlimit << " " << qlimit << endl;
    loop(i, nlimit){
        int r = rand() % 26 + 97;
        cout << (char)r;
    }
    cout << endl;
    loop(i, qlimit){
        int a, b, k;
        while(1){
            a = rand() % nlimit + 1;
            b = rand() % nlimit + 1;
            k = rand() % 2;
            if(a<b) break;
        }
        cout << a << " " << b << " " << k << endl;
    }
}