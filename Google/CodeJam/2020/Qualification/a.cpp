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

void solve(int cs){
    string s;
    cin >> s;
    string ans;
    int p = 0;
    for(auto c : s){
        int dig = c - '0';
        int dif = dig - p;
        p = dig;
        if(dif > 0){
            while(dif--) ans += "(";
            dif = 1;
        }
        if(dif < 0){
            dif = -dif;
            while(dif--) ans += ")";
        }
        ans += c;
    }

    while(p--) ans+= ")";
    printf("Case #%d: ", cs);
    cout << ans << endl;


}

int main(){
    int t;
    cin >> t;
    int i = 1;
    while(t--) solve(i++);
}