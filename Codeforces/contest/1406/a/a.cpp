/**
 * Author: MatijaL
 * Time: 2020-09-12 15:45:01
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
    int a[105];
    memset(a, 0, sizeof a);
    int n;
    cin >> n;
    loop(i, n){
        int temp;
        cin >> temp;
        a[temp]++;
    }
    int mode = 0;
    int cost = 0;
    loop(i, 101){
        int cnt = a[i];
        if(mode == 0 and cnt < 2){
            cost += i;
            mode = 1;
        }
        if(mode == 1 and cnt < 1){
            cost += i;
            break;
        }
    }
    cout << cost << endl;
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
