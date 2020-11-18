/**
 * Author: MatijaL
 * Time: 2020-10-17 16:29:02
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define pii pair<int, int>
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
#define limit 200100

pii hsegtree[3*limit];
pii wsegtree[3*limit];

int h[limit];
int w[limit];

int N;

inline int left(int i){
    return 2*i;
}
inline int right(int i){
    return (2*i)+1;
}
inline int mid(int l, int r){
    return (l+r)/2;
}

int I = 0;
int U = 0;
pii hquery(int i, int l, int r, int ql, int qr){
    I++;
    if(qr < l or r < ql) return mp(inf, 0);

    //v celoti not
    if(ql <= l and r <= qr) return hsegtree[i];

    ll m = mid(l, r);
    return min(
            hquery(left(i), l, m, ql, qr),
            hquery(right(i), m+1, r, ql, qr)
            );
}
pii wquery(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return mp(inf, 0);

    //v celoti not
    if(ql <= l and r <= qr) return wsegtree[i];

    ll m = mid(l, r);
    return min(
            wquery(left(i), l, m, ql, qr),
            wquery(right(i), m+1, r, ql, qr)
            );
}
void build(int i, int l, int r){
    if(l==r){
        hsegtree[i] = mp(h[l], l);
        wsegtree[i] = mp(w[l], l);
        return;
    }
    int m = mid(l, r);

    build(left(i), l, m);
    build(right(i), m+1, r);

    hsegtree[i] = min(hsegtree[left(i)], hsegtree[right(i)]);
    wsegtree[i] = min(wsegtree[left(i)], wsegtree[right(i)]);
}

ll getArea(int l, int r){
    ll H = hquery(1, 1, N, l, r).fs;
    ll W = wquery(1, 1, N, l, r).fs;
    ll len = r-l+1;
    return len*H*W;
}
ll globalMax = 0;
ll MH = 0;
ll MW = 0;
set<pll> visited;
void dp(int l, int r){
    if(l > r) return;
    pll p = mp(l, r);
    if(visited.count(p)) return;
    visited.insert(p);
    if(l == r){
        globalMax = max(globalMax, 1LL*h[l]*w[l]);
        return;
    }
    
    U++;
    pll H = hquery(1, 1, N, l, r);
    pll W = wquery(1, 1, N, l, r);

    ll hDiv = H.sc;
    ll wDiv = W.sc;


    ll len = r-l+1;
    globalMax = max(globalMax, 1LL*len*H.fs*W.fs);
    
    if(len*MH*MW < globalMax) return;
   // printf("L %d - R %d | Area %lld| hdiv %lld - wDiv %lld\n", l, r, getArea(l, r), hDiv, wDiv);

    //dp(hDiv, hDiv);
    dp(l, hDiv-1);
    dp(hDiv+1, r);

    //dp(wDiv, wDiv);
    dp(l, wDiv-1);
    dp(wDiv+1, r);

}

void solve(){
    scanf("%d", &N);
    loop(i, N){
        ll a, b;
           //a = rand()%100000;
       //b = rand()%100000;
        scanf("%lld %lld", &a, &b);
        h[i+1] = a;
        w[i+1] = b;

        MH = max(MH, a);
        MW = max(MW, b);
    }
    build(1, 1, N);
    dp(1, N);
    cout << globalMax << endl;
    //cout << I << endl;
    //cout << U << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

