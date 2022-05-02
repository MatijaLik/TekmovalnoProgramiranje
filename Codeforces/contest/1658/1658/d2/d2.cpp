/**
 * Author: MatijaL
 * Time: 2022-03-27 16:35:02
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
    int l, r;
    cin >> l >> r;
    int n = r-l+1;
    
    int x = 0;
    
    //printf("=====\n");
    
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    
    
    
    for(int b = 20; b >= 0;b--){
        
        
        int c0=0, c1=0;
        FOR(i, l, r){
            if(i & (1<<b)) c1++;
            else c0++;
        }
        
        
        if(c0==c1) continue;
        //printf("bit %d| %d-%d\n", b, lr, rr)
        
        int cnt0=0, cnt1=0;
        for(auto e : v){
            if(e & (1<<b)) cnt1++;
            else cnt0++;
        }
        
        
        printf("bt %d - %d %d\n", b, cnt0, cnt1);
        
        assert(min(cnt0, cnt1) == min(c0, c1));
        assert(max(cnt0, cnt1) == max(c0, c1));
        if(cnt0 != c0 or cnt1!=c1){
            printf("switch\n");
            x |= (1<<b);
            loop(i, n){
                v[i] ^= (1<<b);
            }
        }
        
    }
    
    
    for(auto e : v){
        bool err = false;
        for(int b = 20; b >= 0;b--){
            int c0=0, c1=0;
            FOR(i, l, r){
                if(i & (1<<b)) c1++;
                else c0++;
            }
            
            if(c0==c1) continue;
            if(e & (1<<b) != l & (1<<b)) err=true;
        }
       
        if(!err){
            printf("match %d %d\n", e, l);
            x ^= (e ^ l);
            continue;
        }
    }
    
    
    cout << x << endl;
    
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
