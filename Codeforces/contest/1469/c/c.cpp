/**
 * Author: MatijaL
 * Time: 2021-01-07 22:30:32
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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    k--;
    int t = v.size();
    for(int i = 1; i < t; i++){
        if(abs(v[i] - v[i-1]) >2* k){
                cout << "no" << endl;
                return;
                }
    }
    cout << "yes" << endl;
    return;
    if(abs(v[0]-v[1]) > k){
        cout << "no" << endl;
        return;
    }
    if(abs(v[t-1] - v[t-2]) > k){
        cout << "no" << endl;
        return;
    }
    for(int i = 1; i < t-1; i++){
        ll prev = v[i-1];
        ll cur = v[i];
        ll next = v[i+1];
        if(cur == next) continue;
        if(abs(cur-next) > 2*k){
            cout << "no" << endl;
            return;
        }

        if(next > cur){
            v[i] = min(v[i-1] + k, v[i]+k);
        }
        if(next < cur){
            v[i] = max(v[i], v[i-1]-k);
        }

    }
    print(v);
    cout << "yes" << endl;
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
