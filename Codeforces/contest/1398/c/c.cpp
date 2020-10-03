/*
 * Author: MatijaL
 * Time: 2020-08-16 19:01:25
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
#define inf 1000000000
#define mod 1000000007

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	for(auto c : s){
		v.pb((int) c - (int)'1');
	}
    map<int, int> cs;
    ll rs = 0;
    ll ans = 0;
    cs[0] = 1;//zacetna nicla
    for(auto c : v){
        //cout << c << endl;
        rs += c;
        ans += cs[rs];
        cs[rs]++;
    }
    cout << ans << endl;
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
