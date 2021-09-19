/**
 * Author: MatijaL
 * Time: 2021-05-22 11:35:21
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

#define limit 100200
#define DEBUG 0
int N, Q;
int arr[limit];
multiset<int> seg[4*limit];

//node i ima vrednost v arr[pos[i]]
vector<int> children[limit];
int pos[limit];
int konec[limit];
int cas = 0;

void dfs(int node){
    pos[node] = ++cas;
    for(auto e : children[node]) dfs(e);
    konec[node] = cas;
}


int left(int i){return 2*i;}
int right(int i){return 2*i + 1;}
int mid(int l, int r) {return (l+r)/2;}

void insert(int i, int l, int r, int q, int val){
    //zunaj
    if(q < l or r < q) return;

    if(DEBUG)printf("correcting interval %d %d\n",l, r);

    //izbrisi starega
    auto it = seg[i].find(arr[q]);
    if(it!=seg[i].end()) seg[i].erase(it);

    seg[i].insert(val);

    if(l==r) return;
    int m = mid(l, r);
    insert(left(i), l, m, q, val);
    insert(right(i), m+1, r, q, val);
}

int query(int i, int l, int r, int ql, int qr, int val){
    //zunaj
    if(qr < l or r < ql) return inf;

    if(DEBUG)printf("query %d %d -> ", l, r);

    //v celoti not
    if(ql <= l and r <= qr){
        auto it = seg[i].lower_bound(val);
        int ans;
        if(it == seg[i].end()) ans = inf;
        else ans = *it;
        if(DEBUG)printf("%d\n", ans);
        return ans;
    }

    //neke ono na pol
    int m = mid(l, r);
    int e1 = query(left(i), l, m, ql, qr, val);
    int e2 = query(right(i), m+1, r, ql, qr, val);
    if(DEBUG)printf("%d\n", min(e1, e2));
    return min(e1, e2);
}

void solve(){
    cin >> N >> Q;
    FOR(i,2,N){
        int par;
        cin >> par;
        children[par].pb(i);
    }

    dfs(1);

    if(DEBUG)FOR(i, 1, N) printf("%d -> %d-%d\n", i, pos[i], konec[i]);

    //build segtree
    FOR(i, 1, N){
        int val;
        cin >> val;
        insert(1, 1, N, pos[i], val);
        arr[pos[i]] = val;
    }

    //queryji
    FOR(i, 1, Q){
        int t;
        cin >> t;
        if(t == 2){
            int s, v;
            cin >> s >> v;
            insert(1, 1, N, pos[s], v);
            arr[pos[s]] = v;
        }else{
            int s, v;
            cin >> s >> v;
            int ans = query(1, 1, N, pos[s], konec[s], v);

            if(ans == inf) ans = -1;
            cout << ans << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();   
}
