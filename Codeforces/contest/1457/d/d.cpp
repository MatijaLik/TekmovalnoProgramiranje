/**
 * Author: MatijaL
 * Time: 2020-11-29 14:08:46
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
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];

    loop(i, n-1){
        bool b1 = true;
        bool b2 = true;
        int val = v[i]^v[i+1];
        if(i > 0){
            b1 = v[i-1] <= val; 
        }
        if(i < n-2){
            b2 =  val <= v[i+2];
        }

        if(not(b1 and b2)){
            cout << 1 << endl;
            return;
        }
    }

    assert(n <= 64);
    int best = inf;
    FOR(mid, 0, n-2){
        FOR(left, 0, mid){
            FOR(right, mid+1, n-1){

                int L = 0;
                int R = 0;
                int cnt = (mid-left) + (right - mid - 1);

                FOR(i, left, mid) L ^= v[i];
                FOR(i, mid+1, right) R ^= v[i];

                if(R < L) best = min(best, cnt);

            }
        }
    }

    if(best != inf){
        cout << best << endl;
        return;
    }
    cout << -1 << endl;
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
     solve();   
}
