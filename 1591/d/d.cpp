/**
 * Author: MatijaL
 * Time: 2021-12-12 16:15:02
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
    set<int> s;
    for(auto e : v) s.insert(e);
    if(s.size() < n){
        cout << "YES" << endl;
        return;
    }
    
    int id = 0;
    vector<int> a = v;
    sort(all(a));
    map<int, int> idm;
    for(auto e:a) idm[e] = id++;
    for(auto &e:v)e = idm[e];  
    int pos[n];
    for(int i = 0;i<n;i++){
        pos[v[i]] = i;
    }
    
    //print(v);
    
    //gremo sortirat
    for(int a = 0; a < n-2;a++){
        int b = pos[a];
        int c = n-1;
        if(b == c) c = n-2;
        if(a == b) continue;
        
        int l = v[a];
        int r = v[c];
        
        //cout << "taking: " << a << " " << b << " " << c << endl;
        
        v[a] = a;
        
        v[b] = r;
        pos[r] = b;
        
        v[c] = l;
        pos[l] = c;
        
        //print(v);
    }
    
    if(n == 1 or v[n-2] < v[n-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
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
