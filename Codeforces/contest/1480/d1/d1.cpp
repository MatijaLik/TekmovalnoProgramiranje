/**
 * Author: MatijaL
 * Time: 2021-02-07 15:35:02
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

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    stack<int> s1, s2;
    s1.push(0);
    s2.push(0);

    int ans = 0;
    loop(i, n){
        int e = v[i];
        if(s1.top() == e){
            if(s2.top() != e)ans++;
            s2.push(e);
        }else if(s2.top() == e){
            if(s1.top() != e) ans++;
            s1.push(e);
        }else{
            int a = s1.top();
            int b = s2.top();
            ans++;
            if(i == n-1) continue;
            int next = v[i+1];
            if(next == s2.top()) s2.push(e);
            else s1.push(e);

        }
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
