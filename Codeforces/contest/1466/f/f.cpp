/**
 * Author: MatijaL
 * Time: 2021-01-02 20:08:37
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
#define limit 500100

int sz[limit];
int par[limit];
bool one[limit];

int find(int x){
    if(par[x]==x) return x;
    par[x] = find(par[x]);
    return par[x];
}

void un(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(sz[y] > sz[x]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    if(one[y]) one[x] = true;
}



void solve(){
    loop(i, limit){ sz[i]=1; par[i] = i;}
    int N, M;
    cin >> N >> M;
    vector<int> v;
    loop(i, N){
        int k;
        cin >> k;
        if(k==1){
            int a;
            cin >> a;
            a = find(a);
            if(one[a]) continue;
            one[a] = true;
            v.pb(i+1);
        }else{
            int a, b;
            cin >> a >> b;
            a = find(a);
            b = find(b);
            if(a==b) continue;
            if(one[a] and one[b]) continue;
            un(a, b);
            v.pb(i+1);
        }
    }
    ll T = v.size();
    ll ans = 1;
    loop(i, T){
        ans *= 2;
        ans %= mod;
    }
    cout << ans << " " << T << endl;
    print(v);
    return;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
     solve();   
}
