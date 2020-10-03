/**
 * Author: MatijaL
 * Time: 2020-08-30 16:35:02
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
void pv(vector<ll> v){
    for(auto e : v){
        printf("%lld ", e);
    }
    printf("\n");
}
void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    
    if(n==1){
        printf("1 1\n");
        printf("%lld\n", -v[0]);
        
        printf("1 1\n");
        printf("0\n");

        printf("1 1\n");
        printf("0\n");

        return;
    }
    //first move
    printf("1 %lld\n", n-1);
    loop(i, n-1){
        printf("%lld ", (n-1)*v[i]);
    }
    printf("\n");

    //second
    printf("%lld %lld\n", n, n);
    printf("%lld\n", -v[n-1]);


    //third
    
     printf("1 %lld\n", n);
    loop(i, n){
        if(i == n-1) printf("0 ");
        else printf("%lld ", (-n)*v[i]);
    }
    printf("\n");


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
