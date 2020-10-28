/**
 * Author: MatijaL
 * Time: 2020-10-11 11:05:02
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

void solve(){
    stack<int> s;
    int N;
    cin >> N;
    FOR(i, 1, N) s.push(i);

    cout << 2 << endl;

    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        cout << a << " "  << b << endl;

        s.push((a+b)/2 + ((a+b)%2));
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
