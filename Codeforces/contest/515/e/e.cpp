/**
 * Author: MatijaL
 * Time: 2022-02-28 18:28:25
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

struct Node{
    ll bestL, bestR;
    ll bestIn, totalDist;
    Node(ll _a, ll _b, ll _c, ll _d):
        bestL(_a), bestR(_b), bestIn(_c), totalDist(_d){}
};

template <typename T>
struct Segtree{
    vector<Node> seg;
    vector<T> v;
    Node buildNode(ll pos){
        return Node(
            v[pos].fs,
            v[pos].fs,
            v[pos].fs,
            0
        );
    }
    Node merge(Node A, Node B, ll m){
        ll mid = v[m].sc;
        if(A.bestIn==0) return B;
        if(B.bestIn==0) return A;
        return Node(
            max(A.bestL, A.totalDist+mid+B.bestL),
            max(A.bestR+mid+B.totalDist, B.bestR),
            max(A.bestR+mid+B.bestL, max(A.bestIn, B.bestIn)),
            A.totalDist+mid+B.totalDist
        );
    }
    void build(vector<T> _v){
        v = _v;
        seg.reserve(4*v.size());
        _build(1, 1, v.size()-1);
    }
    Node _build(ll i, ll l, ll r){
        if(l==r)
            return seg[i]=buildNode(l);
        else
            return seg[i] = merge(
                _build(2*i, l, (l+r)/2),
                _build(2*i+1, (l+r)/2+1, r),
                (l+r)/2
            );
    }
    Node _query(ll i, ll l, ll r, ll ql, ll qr){
        if(qr < l || r < ql) return Node(0,0,0,0);
        if(ql <= l && r <= qr) return seg[i];
        return merge(
            _query(2*i, l, (l+r)/2, ql, qr),
            _query(2*i+1, (l+r)/2+1, r, ql, qr),
            (l+r)/2
        );
    }
    ll query(ll l, ll r){
        Node ans = _query(1, 1, v.size()-1, l, r);
        return ans.bestIn;
    }
};

void solve(){
    ll N, Q;
    cin >> N >> Q;
    vector<pll> a(2*N+1);
    loop(i, N) cin >> a[i+1].sc;
    loop(i, N) cin >> a[i+1].fs;
    loop(i, N) a[i+1].fs *= 2;
    
    
    Segtree<pll> S;
    copy(a.begin()+1, a.begin()+N+1, a.begin()+N+1);
    S.build(a);
    
    loop(q, Q){
        ll a, b;
        cin >> a >> b;
        if(a <= b) cout << S.query(b+1, a+N-1) << endl;
        else cout << S.query(b+1, a-1) << endl;
    }
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
