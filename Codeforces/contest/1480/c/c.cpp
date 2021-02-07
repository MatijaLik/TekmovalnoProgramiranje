/**
 * Author: MatijaL
 * Time: 2021-02-07 15:35:02
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
int query(int i){
    cout << "? " << i << endl;
    cout << flush;
    int res;
    cin >> res;
    return res;
}
void ans(int i){
    cout << "! " << i << endl;
    cout << flush;
    return;
}
void solve(){

    int n;
    cin >> n;

    if(n == 1){
        ans(1);
        return;
    }
    if(n == 2){
        int a1, a2;
        a1 = query(1);
        a2 = query(2);
        if(a1 < a2) ans(1);
        else ans(2);
        return;
    }
    int a1, a2, an1, an;
    a1 = query(1);
    a2 = query(2);
    an1 = query(n-1);
    an = query(n);

    if(a1 < a2){
        ans(1);
        return;
    }
    if(an1 > an){
        ans(n);
        return;
    }
    

    int L = 1;
    int R = n;
    int M;
    while(1){
        if(L+2 == R) {
            ans(L+1);
            return;
        }
        int am, am1;
        M = (L+R)/2;
        am = query(M);
        am1 = query(M+1);

        if(am > am1) L = M;
        else R = M+1;
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
