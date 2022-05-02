/**
 * Author: MatijaL
 * Time: 2022-03-27 16:35:02
**/

#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
struct FenwickTree{
    int sz;
    unsigned int v[6505][6505];
    
    void x_range_add(int xl, int xr, int yl, int yr, int val){
        //printf("inserting %d %d %d %d\n", xl, xr, yl, yr);
        x_add(xl, yl, yr, val);
        x_add(xr+1, yl, yr, -val);
    }
    
    void x_add(int x, int yl, int yr, int val){
        for(; x<6505; x += x & -x)
            y_range_add(x, yl, yr, val);
    }
    
    void y_range_add(int x, int yl, int yr, int val){
        y_add(x, yl, val);
        y_add(x, yr+1, -val);
    }
    
    void y_add(int x, int y, int val){
        for( ; y < 6505; y += y & -y){
            v[x][y] += val;
            v[x][y] %= mod;
        }
    }
    
    int x_query(int x, int y){
        //printf("querying %d %d\n", x, y);
        int sum = 0;
        for(; x>0;x -= x & -x)
            sum += y_query(x, y);
        return sum;
    }
    
    int y_query(int x, int y){
        int sum = 0;
        for(; y > 0; y -= y&-y)
            sum += v[x][y];
        return sum % mod;
    }
    
};


void solve(){
    FenwickTree F;
    const int shift = 2005;
        
const int N = 6505;
    int n, k;
    cin >> n >> k;
    
    pll m[n*n+1];
    FOR(x, 1, n){
        FOR(y, 1, n){
            int t;
            cin >> t;
            m[t] = mp(x, y);
        }
    }
    
    int zmag = 0;
    
    char gud[n+1][n+1];
    for(int i = n*n; i>=0;i--){
        pll p = m[i];
        int x = p.fs;
        int y = p.sc;
        
        
        
        int a = F.x_query(x+y+shift, x-y+shift);
        //printf("%d %d\n", i, a);
        //vsi zmagovalni so notri
        if(a==zmag%mod){
            gud[x][y] = 'M';
            zmag++;
            
            //vstavi
            F.x_range_add(
                    max(min(N-10, x+y-k+shift), 0), 
                    max(min(N-10, x+y+k+shift), 0), 
                    max(min(N-10, x-y-k+shift), 0), 
                    max(min(N-10, x-y+k+shift), 0), 
                     1
                     );
            
        }
        else gud[x][y] = 'G';
    }
    
    FOR(x, 1, n){
        FOR(y, 1, n){
            cout << gud[x][y];
        }
        cout << endl;
    }
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
