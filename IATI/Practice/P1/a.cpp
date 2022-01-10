/**
 * Author: MatijaL
 * Time: 2021-11-25 13:19:33
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


int par[20500];
int sz[20500];

int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}
void un(int a, int b){
    a = find(a);b=find(b);
    if(a==b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void solve(){

    int N;
    cin >> N;
    vector<pll> s;
    loop(i, N){
        int a, b;
        cin >> a >> b;
        s.pb(mp(a, b));
    }
    sort(all(s));
    vector<int> v;
    for(auto e : s)v.pb(e.sc);
    //print(v);
    //LDS
    ll ans = 0;
    vector<ll> LDS(N, 0);
    loop(i, N){
        ll best = 1;
        FOR(j, 0, i-1){
            if(v[i] < v[j]) best = max(best, LDS[j]+1);
        }
        LDS[i] = best;
        ans = max(ans, LDS[i]);
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();  
}
