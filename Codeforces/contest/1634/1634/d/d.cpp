/**
 * Author: MatijaL
 * Time: 2022-02-06 15:35:02
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


ll query(int i, int j, int k){
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}

void answer(int i, int j){
    cout << "! "<< i << " " << j << endl;
    cout.flush();
    return;
}

void solve(){
    int N;
    cin >> N;
    
    bool const_first = true;
    ll mx_first = -1;
    ll mxi_first = -1;
    int a=1, b=2;
    FOR(p, 3, N){
        ll ans = query(a, b, p);
        if(ans!=mx_first&&p!=3) const_first=false;
        if(ans>mx_first){
            mx_first = ans;
            mxi_first = p;
        }
    }
    
    int c = mxi_first;
    int d = a;
    
    bool const_second=true;
    ll mx_second = -1;
    ll mxi_second = -1;
    FOR(p, 2, N){
        if(p==c) continue;
        ll ans = query(c, d, p);
        if(ans!=mx_second&&p!=2) const_second=false;
        if(ans > mx_second){
            mx_second = ans;
            mxi_second=p;
        }
    }
    
    if(mx_first>=mx_second && const_first){
        answer(a, b);
    }else{
        if(const_second){
            answer(c, d);
        }else{
            answer(c, mxi_second);
        }
    }
    
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
