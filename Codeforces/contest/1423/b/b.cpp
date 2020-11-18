/**
 * Author: MatijaL
 * Time: 2020-11-09 22:06:58
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



#define limit 20100
int par[limit];
int fs[limit];
int as[limit];

int find(int node){
    if(node != par[node]){
       return par[node] = find(par[node]);
    }
    return node;  
}

int un(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return x;
    int s1 = fs[x] + as[x];
    int s2 = fs[y] + as[y];

    if(s1 < s2) swap(x, y);

    par[y] = x;
    fs[x] += fs[y];
    as[x] += as[y];

    return x;
}

void solve(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, pll>> vec;
    
    FOR(i, 1, 2*N){
        par[i] = i;
        if(i <= N){
            fs[i] = 0;
            as[i] = 1;
        }else{
            fs[i] = 1;
            as[i] = 0;
        }
    }
    int comps = 2*N;
    set<int> good;

    loop(i, M){
        int u, v, c;
        cin >> u >> v >> c;
        v += N;
        vec.pb(mp(c, mp(u, v)));
    }
    sort(all(vec));

    for(auto e : vec){
        int u, v, c;
        c = e.fs;
        u = e.sc.fs;
        v = e.sc.sc;

        printf("%d %d %d\n", u, v, c); 
         u = find(u);
        v = find(v);

        if(u == v) continue;
        comps--;
 
        if(good.find(u) != good.end())good.erase(good.find(u));
        if(good.find(v) != good.end())good.erase(good.find(v));

        int m = un(u, v);
       

        if(as[m] == fs[m]) good.insert(m);

        printf("%d %d| %d %d\n", good.size(), comps, as[m], fs[m]);
        if(good.size() == comps){
            cout << c << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
