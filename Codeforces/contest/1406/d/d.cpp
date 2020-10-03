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
ll getAns(ll a, ll b){
    return ceil(((double) a + (double)b)/2);
}
void solve(){
    int n;
    cin >> n;
    ll a[n];
    ll diff[n];
    loop(i, n) cin >> a[i];
    FOR(i, 1, n-1) diff[i] = a[i] - a[i-1];
    
    ll top1 = a[0];
    ll top2 = 0;
    FOR(i, 1, n-1) if(diff[i] > 0) top2 += diff[i];
    
    cout << getAns(top1, top2) << endl;
    int Q;
    cin >> Q;
    while(Q--){
        ll l, r, x;
        cin >> l >> r >> x;

        //adjust indeces
        l--;
        r--;

        //leva stran
        if(l != 0){
            ll lprev = diff[l];
            diff[l] += x;
        
            if(lprev > 0) top2 -= lprev;
            if(diff[l] > 0) top2 += diff[l];
        }


        //desna stran
        if(r != n-1){
            ll rprev = diff[r+1];
            diff[r+1] -= x;
            //printf("%d %d\n", rprev, diff[r+1]);
            if(rprev > 0) top2 -= rprev;
            if(diff[r+1] > 0) top2 += diff[r+1];

        }
        if(l == 0) top1 += x;
        //printf("top2 is %lld\n", top2); 
        cout << getAns(top1, top2) << endl;
    }
      
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
