/**
 * Author: MatijaL
 * Time: 2022-02-03 16:04:45
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
    vector<int> v(n);
    for(int i=0;i<n;i++) v[i]=i;

    if(k == n-1){
        if(n <= 4){
            cout << -1 << endl;
        }else{
            int tag[n];
            for(int i =0;i<n;i++)tag[i] = false;
            //sestavi
            swap(v[0], v[n-1-1]);
            swap(v[n-1-1], v[3]);
            for(int i=0;i<n/2;i++){
                cout << v[i] << " " << v[n-1-i] << endl;
            }   
        }
    }else{
        swap(v[0], v[k]);
        for(int i=0;i<n/2;i++){
            cout << v[i] << " " << v[n-1-i] << endl;
        }
    }
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(t--) solve();   
}
