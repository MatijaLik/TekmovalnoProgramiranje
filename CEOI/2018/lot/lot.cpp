/**
 * Author: MatijaL
 * Time: 2021-08-21 16:32:40
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
    int n, l;
    cin >> n >> l;
    int a[n];
    loop(i, n) cin >> a[i];
    int q;
    cin >> q;
    vector<int> Q(q);
    loop(i, q) cin >> Q[i];
    vector<int> K = Q;
    sort(all(K));
    int bij[l+1];
    FOR(k, 0, l){
        auto it = lower_bound(all(K), k);
        if(it != K.end()) bij[k] = it - K.begin();
        else bij[k] = -1; 
    }
    

    int ans[n-l+1][q];
    memset(ans, 0, sizeof ans);

    FOR(shift, 1, n-l){
        int dist = 0;
        FOR(i, 0, n-l-shift){
            if(i == 0){
                //bf
                loop(j, l) if(a[i+j] != a[i+shift+j]) dist++;
            }else{
                //greedy
                if(a[i-1] != a[i+shift-1]) dist--;
                if(a[i+l-1] != a[i+shift+l-1]) dist++;
            }
            
            if(bij[dist] != -1){
                ans[i][bij[dist]]++;
                ans[i+shift][bij[dist]]++;
            }
       }
    }
   

    //naredi cumsum
    loop(j, n-l+1){
        int cs = 0;
        loop(i, q){
            cs += ans[j][i];
            ans[j][i] = cs;
        }
    }
    loop(i, q){
        loop(j, n-l+1){
            printf("%d ", ans[j][bij[Q[i]]]);
        }
        printf("\n");
    }


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
