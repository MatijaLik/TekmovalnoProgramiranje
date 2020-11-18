/**
 * Author: MatijaL
 * Time: 2020-11-08 18:32:40
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

int resi(vector<int> a, vector<int> b){
    ll res = 0;
    //win
    loop(i, 3){
        int h = min(a[i], b[(i+1)%3]);
        res += h;
    }
    return res;
}

int benis(vector<int> a, vector<int> b){
    ll res = 0;
    
    cur = 0;
    res = max(cur, ) 
    


    cout << res << endl;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(3);
    vector<int> b(3);

    loop(i, 3) cin >> a[i];
    loop(i, 3) cin >> b[i];
    cout << benis(a, b) << " ";
    cout << resi(a, b) << endl;
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
