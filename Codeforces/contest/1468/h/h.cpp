/**
 * Author: MatijaL
 * Time: 2021-01-09 18:15:47
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
    int n, k, m;
    cin >> n >> k >> m;
    int color[n];
    memset(color, 0, sizeof color);

    loop(i, m){
        int t;
        cin >> t;
        color[t-1] = 1;
    }

    int vse = 0;
    vector<int> bk;
    int cur = 0;
    int K = (k-1)/2;
    loop(i, n){
        if(color[i] == 0) cur++;
        else{
            while(cur - 2*K >= 1) cur -= 2*K;
            if(cur){
                bk.pb(cur);
                vse += cur;
                cur = 0;
            }
        }
    }

    while(cur - 2*K >= 1) cur -= 2*K;
    if(cur) bk.pb(cur);
    vse += cur;

    if(bk.size() == 1){
        cout << "no" << endl;
        return;
    }
    if(bk.size() == 0){
        cout << "yes" << endl;
        return;
    }
    int t = bk.size(); 
    if(vse % 2*K){
        cout << "no" << endl;
        return;
    }
    for(auto e : bk){
        if(e > vse-e){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    return;
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
