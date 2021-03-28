/**
 * Author: MatijaL
 * Time: 2021-03-27 14:02:47
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

#define limit 200500
#define DEBUG 1

void solve(){
    printf("10\n");
    loop(i, 10){
        int n = 100000;
        int m = 100000;
        printf("%d %d\n", n, m);

        loop(i, m){
            int a = rand()%n +1;
            int b = rand()%n + 1;
            if(a == b) b = (a+1)%n + 1;
            printf("%d %d %d\n", a, b, rand()%2);
        }
    }
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
