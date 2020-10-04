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
pll cut(ll a){
    return mp(a/2, a-(a/2));
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    loop(i, n){
        ll a;
        cin >> a;
        v.pb(a);
    }
    sort(all(v));

    int l = 1;
    int r = inf;
    int mid;
    while(l < r){
        //printf("%lld %lld\n", l, r);
        mid = (l+r)/2;

        //poglej ce gre
        int stock = k;
        for(auto plank :  v){
            if(plank <= mid) continue;
            stock -= ceil((double)(plank)/(double)(mid)) - 1;
            if(stock < 0) break;
        }
        //printf("%d\n", stock);
        if(stock >= 0) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
}
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
