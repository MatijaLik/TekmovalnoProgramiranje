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
#define mod 998244353
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    vector<ll> fixed(n+1, 0);
    
    //floodfill desno
    ll fixedOn = 0;
    for(int i = 0; i < n;i++){
        ll e = v[i];
        if(e>2) fixedOn = 0;
        if(fixedOn){
            if(e == 2){
                fixedOn = fixedOn==1 ? 2 : 1;
                fixed[i] = fixedOn;
            }
            if(e == 1){
                fixed[i] = 1;
                if(fixedOn == 1){
                    cout << 0 << endl;
                    return;
                }
                fixedOn = 1;
            } 
        }
        if(e == 1) {
            fixedOn = 1;
            fixed[i] = 1;
        }
    }
    
    //levo
    fixedOn = 0;
    for(int i = n-1; i >= 0;i--){
        ll e = v[i];
        if(e>2) fixedOn = 0;
        if(fixedOn){
            if(e == 2){
                fixedOn = fixedOn==1 ? 2 : 1;
                fixed[i] = fixedOn;
            }
            if(e == 1){
                fixed[i] = 1;
                if(fixedOn == 1){
                    cout << 0 << endl;
                    return;
                }
                fixedOn = 1;
            } 
        }
        if(e == 1) {
            fixedOn = 1;
            fixed[i] = 1;
        }
    }
    
    //(fixed);
    
    vector<ll> ans = {1, 0, 0};
    for(int i = 0; i < n; i++){
        vector<ll> next = {0, 0, 0};
        if(fixed[i]){
            if(fixed[i]==1)
                next[1] = ans[0] + ans[2];
            if(fixed[i]==2)
                next[2] = ans[0] + ans[1];
            
        }else{
            if(v[i]>2)next[0] = (v[i]-2)( ans[1] + ans[2]) + ans[0]*(v[i]-3);
            
            next[1] = ans[0] + ans[2];
            next[2] = ans[0] + ans[1];
            
            if(i != n-1 && fixed[i+1])       
                next[fixed[i+1]] = 0;
        }
        loop(i, 3)
        ans[i] = next[i]%mod;
        
        print(ans);
    }
    cout << (ans[0] + ans[1] + ans[2])%mod << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
