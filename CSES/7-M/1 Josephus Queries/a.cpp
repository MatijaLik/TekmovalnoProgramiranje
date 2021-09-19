/**
 * Author: MatijaL
 * Time: 2021-06-28 21:02:39
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
//#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;


int f(int n, int k, int div, int mod, bool carry){
    //if(k == 1) return 1;
    //katere ubijemo? n/2

    //printf("%d %d %d %d\n", n, k, div, mod);
    //if(carry) printf("carry\n");
    if(n==1 and div==2) return 1;
    if(n == 1) return mod % (div/2);
    int dec = carry ? n/2 + n%2 : n/2;
    if(k <= dec){
        if(div == 2) return 2*k;
        return (k-1)*div + ((mod + div/2)%div);
    }else{
        if(n%2 == carry) return f(n - dec, k - dec, div*2, mod, false);
        else return f(n - dec, k - dec, div*2, mod+div, true);
    }
    
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << f(n, k, 2, 1, false) << endl;
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
