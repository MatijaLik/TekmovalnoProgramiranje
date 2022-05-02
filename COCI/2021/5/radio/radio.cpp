/**
 * Author: MatijaL
 * Time: 2022-03-05 16:19:54
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
#define prll(v) for(auto e : v) cout << e << " "; cout << endl;

#define mod 1000000007
const ll MOD = 998244353;
const ll N = 200043;

ll add(ll x, ll y)
{
	return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
	return add(x, MOD - y);
}

ll mul(ll x, ll y)
{
	return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
	ll z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}
ll inv(ll x)
{
	return binpow(x, MOD - 2);
}

template <typename T, typename U>
struct MulSegtree{
    vector<U> seg;
    vector<T> v;
    U buildNode(ll pos){
        return U(v[pos]);
    }
    U merge(U A, U B){
        return U(mul(A, B));
    }
    
    U _build(ll i, ll l, ll r){
        if(l==r)
            return seg[i]=buildNode(l);
        else
            return seg[i] = merge(
                _build(2*i, l, (l+r)/2),
                _build(2*i+1, (l+r)/2+1, r)
            );
    }
    U _query(ll i, ll l, ll r, ll ql, ll qr){
        if(qr < l || r < ql) return U(1);
        if(ql <= l && r <= qr) return seg[i];
        return merge(
            _query(2*i, l, (l+r)/2, ql, qr),
            _query(2*i+1, (l+r)/2+1, r, ql, qr)
        );
    }
    U _insert(ll i, ll l, ll r, ll pos){
        if(pos < l || r < pos) return seg[i];
        if(l==r) return seg[i] = buildNode(pos);
        return seg[i] = merge(
            _insert(2*i, l, (l+r)/2, pos),
            _insert(2*i+1, (l+r)/2+1, r, pos)
        );

    }
    void build(vector<T> _v){
        v = _v;
        seg.reserve(4*v.size());
        _build(1, 1, v.size()-1);
    }
    U query(ll l, ll r){
        U ans = _query(1, 1, v.size()-1, l, r);
        return ans;
    }
    void insert(ll pos, T val){
        v[pos] = val;
        _insert(1, 1, v.size()-1, pos);
    }
    void add(ll pos, T increment){
        insert(pos, v[pos]+increment);
    }
};

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return mul(mul(a, b), inv(gcd(a, b)));
}

template <typename T, typename U>
struct LcmSegtree{
    vector<U> seg;
    vector<T> v;
    U buildNode(ll pos){
        return U(v[pos]);
    }
    U merge(U A, U B){
        return lcm(A, B);
    }
    
    U _build(ll i, ll l, ll r){
        if(l==r)
            return seg[i]=buildNode(l);
        else
            return seg[i] = merge(
                _build(2*i, l, (l+r)/2),
                _build(2*i+1, (l+r)/2+1, r)
            );
    }
    U _query(ll i, ll l, ll r, ll ql, ll qr){
        if(qr < l || r < ql) return U(1);
        if(ql <= l && r <= qr) return seg[i];
        return merge(
            _query(2*i, l, (l+r)/2, ql, qr),
            _query(2*i+1, (l+r)/2+1, r, ql, qr)
        );
    }
    U _insert(ll i, ll l, ll r, ll pos){
        if(pos < l || r < pos) return seg[i];
        if(l==r) return seg[i] = buildNode(pos);
        return seg[i] = merge(
            _insert(2*i, l, (l+r)/2, pos),
            _insert(2*i+1, (l+r)/2+1, r, pos)
        );

    }
    void build(vector<T> _v){
        v = _v;
        seg.reserve(4*v.size());
        _build(1, 1, v.size()-1);
    }
    T query(ll l, ll r){
        U ans = _query(1, 1, v.size()-1, l, r);
        return ans;
    }
    void insert(ll pos, T val){
        v[pos] = val;
        _insert(1, 1, v.size()-1, pos);
    }
    void add(ll pos, T increment){
        insert(pos, v[pos]+increment);
    }
};

void solve(){
    MulSegtree<ll, ll> M;
    LcmSegtree<ll, ll> L;
    ll N, Q;
    cin >> N >> Q;
    vector<ll> v(N+1, 1);
    M.build(v);
    L.build(v);

    loop(q, Q){
        char t;
        cin >> t;
        if(t=='S'){
            ll f;
            cin >> f;
            if(M.v[f]==1){M.insert(f, f); L.insert(f, f);}
            else {M.insert(f, 1); L.insert(f, 1);}
        }else{
            ll a, b;
            cin >> a >> b;
            ll prod = M.query(a, b);
            ll lcm = L.query(a, b);
            //prllf("%d %d\n", prod, lcm);
            if(prod!=lcm){
                cout << "DA" << endl;
            }else{
                cout << "NE" << endl;
            }
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
