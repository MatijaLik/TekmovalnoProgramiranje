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
#define inf 1000400000
#define mod 1000000007

#define limit 1000100

pair<int, int> segtree[4*limit];
int a[limit];
int N;

ll left(ll i){return 2*i;}
ll right(ll i){return (2*i)+1;}
ll mid(ll l, ll r){
    return (l+r)/2;
}
void build(int i, int l, int r){
    if(l == r){
        segtree[i] = mp(a[l], l);
        return;
    }
    ll m = mid(l, r);
    build(left(i), l, m);
    build(right(i), m+1, r);

    if(segtree[left(i)].fs < segtree[right(i)].fs) segtree[i] = segtree[left(i)];
    else segtree[i] = segtree[right(i)];

    return;
}
pair<int, int> query(int i, int l, int r, int ql, int qr){
    //zunaj
    if(qr < l or r < ql) return mp(inf, -1);

    //v celoti not
    if(ql <= l and r <= qr) return segtree[i];

    int m = mid(l, r);
    return min(
            query(left(i), l, m, ql, qr),
            query(right(i), m+1, r, ql, qr));
}

ll daq(int l, int r, int water){
    //printf("daq %lld %lld _ %lld\n", l, r, water);
    if(l == r and water < a[l]) return 1;
    if(l == r and water >= a[l]) return 0;
    if(l > r) return 0;

    /*
     * 1 najdi najmanjsega
     * 2 cost + daq rekurzivno
     * 3 primerjaj totalCost vs r-l+1
     */

    pair<int, int> neck = query(1, 1, N, l, r);
    int id = neck.sc;
    int level = neck.fs;

    int cost = level - water;
    cost += daq(l, id-1, level);
    cost += daq(id+1, r, level);

    //printf("daq %lld %lld _ %lld ---> %lld\n", l, r, water, min(cost, r-l+1));

    return min(cost, r-l+1);
}

void solve(){
    cin >> N;
    loop(i, N) cin >> a[i+1];

    build(1, 1, N);
    cout << daq(1, N, 0) << endl;
}

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
