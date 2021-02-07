/**
 * Author: MatijaL
 * Time: 2021-01-14 15:35:19
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;
string red(string s){
    int t = s.length();
    FOR(len, 1, t){
        if(t % len) continue;
        bool gud = 1;
        int seg = t/len;
        loop(i, seg-1){
            if(s.substr(len*i, len)!=s.substr(len*(i+1), len))gud = 0;
        }

        if(gud) return s.substr(0, len);
    }
    return "$";
}
int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}
void solve(){
    string a, b;
    cin >> a >> b;
    if(a == b){
        cout << a << endl;
        return;
    }
    if(a.length() < b.length()) swap(a, b);

    if(red(a)==red(b)){

        int t = a.length();
        int u = b.length();
        int lcm = (t*u)/gcd(t, u);
        int rep = lcm/red(a).length();
        loop(i, rep) cout << red(a);
        cout << endl;
    }
    else{
        cout << -1<< endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
