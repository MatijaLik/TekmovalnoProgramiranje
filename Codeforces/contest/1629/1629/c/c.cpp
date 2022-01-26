/**
 * Author: MatijaL
 * Time: 2022-01-22 15:35:03
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
    vector<int> a(n);
    loop(i, n) cin >> a[i];
    priority_queue<int, std::vector<int>, std::greater<int> > pq[200100];
    for(int i = 0; i<n;i++){
        pq[a[i]].push(i);
    }

    vector<int> b;
    int p = 0;
    while(p<n){
        int mex = 0;
        int r = p;
        while(1){
            //pocisti pq;
            while(!pq[mex].empty() && pq[mex].top()<p) pq[mex].pop();
            if(pq[mex].empty()) break;
            r = max(r, pq[mex].top());
            mex++;
        }

        
        b.pb(mex);

        p = r+1;
    }
    cout << b.size() << endl;
    print(b);
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
