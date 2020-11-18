/**
 * Author: MatijaL
 * Time: 2020-10-14 14:58:18
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


    int t;
void solve(){
    vector<int> a(6);
    scanf("%01d%01d:%01d%01d:%01d%01d\n", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);

    int res[6][4];
    memset(res, 0, sizeof res);

    loop(i, 6){
        int p = 0;
        int n = a[i];
        while(p < 4){
        if(n % 2) res[i][3-p] = 1;
        n /= 2;
        p++;}
    }
    loop(i, 4){ loop(j, 6){printf("%d", res[j][i]); } printf("\n");}
    printf("\n");
}

int main(){

    ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d\n", &t);
    while(t--) solve();   
}
