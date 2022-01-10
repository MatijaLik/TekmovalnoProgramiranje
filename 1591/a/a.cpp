/**
 * Author: MatijaL
 * Time: 2021-12-12 16:15:02
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
    int prev = -1;
    int h = 1;
    loop(i, n){
        int t;
        cin >> t;
        if(t == 1 and h!= -1){
            if(i > 0 and prev==1) h+=5;
            else h+=1;
        }else{
            if(prev==0){
                h = -1;
            }
        }
        prev = t;
    }
    cout << h << endl;
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
