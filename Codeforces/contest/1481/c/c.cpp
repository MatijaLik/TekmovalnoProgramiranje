/**
 * Author: MatijaL
 * Time: 2021-02-05 15:35:01
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    loop(i, n) cin >> a[i];
    loop(i, n) cin >> b[i];
    loop(i, m) cin >> c[i];


    vector<int> ans(m, -1);
    
    int anyIndex[n+10];
    loop(i,n+10) anyIndex[i] = -1;

    map<int, queue<int>> indeces;
    set<int> prazni;

    loop(i, n){
        if(a[i] != b[i]){
            indeces[b[i]].push(i);
            prazni.insert(i);
        }

        anyIndex[b[i]] = i+1;
    }
    
    loop(i, m){
        int color = c[i];
        if(indeces[color].empty()) continue;
        ans[i] = indeces[color].front() + 1;
        indeces[color].pop();
    }
   
    FOR(i, 1, n) if(!indeces[i].empty()){
        cout << "NO" << endl;
        return;
    }
    reverse(all(ans));
    queue<int> gud;
    loop(i, m){
        int e = ans[i];
        if(e != -1) gud.push(e);
        else{
            if(anyIndex[c[m-i-1]] != -1){
                ans[i] = anyIndex[c[m-i-1]];
                gud.push(ans[i]);
                continue;
            }
            if(gud.empty()){
                cout << "NO" << endl;
                return;
            }
            ans[i] = gud.front();
        }
    }
    reverse(all(ans));
    cout << "YES" << endl;
    print(ans);
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
