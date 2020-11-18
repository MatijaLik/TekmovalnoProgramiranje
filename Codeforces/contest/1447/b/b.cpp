/**
 * Author: MatijaL
 * Time: 2020-11-15 15:35:01
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
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    int X = 0;

    int neg = 0;
    int pos = 0;

    int mn = inf;
    int mx = 0;

    loop(i, n) loop(j, m){
        int t;
        cin >> t;
        grid[i][j] = t;
        X += abs(t);

        mn = min(abs(t), mn);
        mx = max(abs(t), mx);

        if(t < 0) neg++;
        if(t >= 0) pos++;
    }

    if(n*m % 2 == 0){
        if(neg % 2 == 0 and pos % 2 == 0){
            cout << X << endl;
            return;
        }else{
            cout << X - 2*mn << endl;
            return;
        }
    }else{
        if(neg % 2 == 0){
            cout << X << endl;
        }else{
            cout << X - 2*mn << endl;
        }
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
