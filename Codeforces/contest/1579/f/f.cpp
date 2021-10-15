/**
 * Author: MatijaL
 * Time: 2021-09-28 16:35:02
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
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    
    bool visited[n];
    memset(visited, 0, sizeof visited);loop(i, n) cin >> v[i];
    queue<pll>q;
    loop(i, n){
        if(v[i] == 0){
            q.push(mp(i, 0));
            visited[i] = true;
        }
    }
    int time = 0;
    while(!q.empty()){
        int pos = q.front().fs;
        time = q.front().sc;
        q.pop();
        int nx = pos - d;
        nx = (nx + n) % n;
        if(!visited[nx]){
            visited[nx] = true;
            q.push(mp(nx, time+1));
        }
    }
    loop(i, n) if(!visited[i]){
        cout << -1 << endl;
        return;
       }

   cout << time << endl;
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
