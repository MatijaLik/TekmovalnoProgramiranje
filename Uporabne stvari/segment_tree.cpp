#include<vector>
using namespace std;
template <typename T, typename U>
struct Segtree{
    vector<U> seg;
    vector<T> v;
    U buildNode(int pos){
        return U(v[pos]);
    }
    U merge(U A, U B){
        return U(A+B);
    }
    
    U _build(int i, int l, int r){
        if(l==r)
            return seg[i]=buildNode(l);
        else
            return seg[i] = merge(
                _build(2*i, l, (l+r)/2),
                _build(2*i+1, (l+r)/2+1, r),
                (l+r)/2
            );
    }
    U _query(int i, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return U(0);
        if(ql <= l && r <= qr) return seg[i];
        return merge(
            _query(2*i, l, (l+r)/2, ql, qr),
            _query(2*i+1, (l+r)/2+1, r, ql, qr)
        );
    }
    void _insert(int i, int l, int r, int pos){
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
    T query(int l, int r){
        U ans = _query(1, 1, v.size()-1, l, r);
        return ans.bestIn;
    }
    void insert(int pos, T val){
        v[pos] = val;
        _insert(1, 1, v.size()-1, pos);
    }
    void add(int pos, T increment){
        insert(pos, v[pos]+increment);
    }
};