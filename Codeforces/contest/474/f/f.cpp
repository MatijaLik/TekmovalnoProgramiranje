/**
 * Author: MatijaL
 * Time: 2022-02-28 16:49:58
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

#define nlimit 100005

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

struct Segtree{
    pll seg[4*nlimit];
    vector<int> v;
    Segtree(vector<int> _v){
        memset(seg, 0, sizeof seg);
        v = _v;
        build(1, 1, v.size());
    }
    
    pll merge(pll a, pll b){
        int G = gcd(a.fs, b.fs);
        int cnt=0;
        if(a.fs==G) cnt+=a.sc;
        if(b.fs==G) cnt+=b.sc;
        return mp(G, cnt);
    }
    pll build(int i, int l, int r){
        if(l==r)
            return seg[i] = mp(v[l-1], 1);
        else 
            return seg[i] = merge(
                build(2*i, l, (l+r)/2),
                build(2*i+1, (l+r)/2 + 1, r)
            );
    }
    pll _query(int i, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return mp(-1, -1);
        if(ql <= l && r <= qr) return seg[i];
        
        pll A = _query(2*i, l, (l+r)/2, ql, qr);
        pll B = _query(2*i+1, (l+r)/2 + 1, r, ql, qr);
        
        if(A.fs==-1) return B;
        if(B.fs==-1) return A;
        return merge(A, B);
    }
    int query(int l, int r){
        pll A = _query(1, 1, v.size(), l, r);
        return r-l+1-A.sc;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    Segtree S(v);
    int q;
    cin >> q;
    loop(i, q){
        int l, r;
        cin >> l >> r;
        cout << S.query(l, r) << endl;
    }
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
