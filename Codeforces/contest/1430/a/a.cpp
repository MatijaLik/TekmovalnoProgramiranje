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
int a, b;
int N;
void solve(){
    cin >> N;
    
    FOR(x, 0, 350){
        int three = 3*x;
        FOR(y, 0, 200){
            int five = 5*y;
            int rest = N - three - five;
            if(rest < 0) continue;

            if(rest % 7 == 0){
               int  z = rest / 7;

                if(x < 0 or y < 0  or z < 0) continue;

                cout << x << " " << y << " " << z << endl;
                return;
            }
        }
        
    }
    cout << -1 << endl;


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
