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
#define debug(x) cout << "# " << x << endl;

int main(){
    int n;
    cin >> n;
    string s;
    int a = 0, d = 0;
    cin >> s;
    for(auto c : s){
        if(c=='A') a++;
        else d++;
    }

    if(a > d) cout << "Anton" << endl;
    else if(d > a) cout << "Danik" << endl;
    else cout << "Friendship" << endl;
}