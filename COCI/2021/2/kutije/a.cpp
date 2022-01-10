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
#define inf 1000000000
#define mod 1000000007

int par[2000];
int sz[2000];

int find(int n){
    if(par[n] != n) return par[n] = find(par[n]);
    return n;
}

void un(int a, int b){
    if(find(a)==find(b)) return;
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    loop(i, 2000){
        par[i] = i;
        sz[i] = 1;
    }

    loop(i, m){
        FOR(j, 1, n){
            int t;
            cin >> t;
            un(j, t);
        }
    }

    loop(i, q){
        int a, b;
        cin >> a >> b;
        if(find(a)==find(b) )cout << "DA" << endl;
        else cout << "NE" << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}