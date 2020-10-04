/**
 * Author: MatijaL
 * Time: 2020-08-19 19:48:26
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
#define inf 1000000000
#define mod 1000000007
#define limit 300100
int n, q;
vector<int> sosedi[limit];
int parent[limit];

int w[limit];
int cas = 1;
int in[limit];
int out[limit];
long double segtree[4*limit];

void dfs(int node, int prev){
    in[node] = cas;
    w[in[node]] = 1;
    for(auto sosed : sosedi[node]){
        if(sosed == prev) continue;
        cas++;
        dfs(sosed, node);

    }
    out[node] = cas;
}

ll left(ll i){return 2*i;}
ll right(ll i){return left(i) + 1;}
ll mid(ll l, ll r){return (l+r)/2;}

/*
 *product segment tree
 *without lazy updates
 */

void build(ll i, ll l, ll r){
    if(l==r){
        segtree[i] = log(w[l]);
        return;
    }
    ll m = mid(l, r);
    build(left(i), l, m);
    build(right(i), m+1, r);
    segtree[i] = segtree[left(i)]+segtree[right(i)];
    return;
}

void update(ll i, ll l, ll r, ll val, ll index){
    if(index < l or r < index) return;
    if(l == index and l == r){
        segtree[i] = log(val);
        return; 
    }
    //update both children
    ll m = mid(l, r);
    update(left(i), l, m, val, index);
    update(right(i), m+1, r, val, index);
    segtree[i] = segtree[left(i)]+segtree[right(i)];
}
long double query(ll i, ll l, ll r, ll ql, ll qr){
    if(qr < l or r < ql) return 0;
    //v celoti not   
    if(ql <= l and r <= qr) return segtree[i];
    ll m = mid(l, r);
    return query(left(i), l, m, ql, qr)+
        query(right(i), m+1, r, ql, qr);
}
void solve(){
    cin >> n;
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    dfs(1, 1);
    build(1, 1, n);
    cin >> q;
    loop(i, q){
       int t, x, y;
       cin >> t >> x >> y;
       if(t == 1)update(1, 1, n, y, in[x]);
       else{
           long double lx = query(1, 1, n, in[x], out[x]);
           long double ly = query(1, 1, n, in[y], out[y]);   
           printf("%.10Lf\n", min((long double) 1000000000, exp(lx - ly)));
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

