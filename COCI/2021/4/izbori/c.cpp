#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll shift;
struct Node{
    ll sum;
    ll val;
    ll len;
    ll prop_add=0;
    bool prop_reset=false;
    Node(ll _b, ll _c, ll _d):
        sum(_b), val(_c), len(_d){}
    void calc_add(ll addend){
        sum += len*addend;
        val += addend*((len)*(len+1))/2;
    }
    void calc_reset(){
        sum=0;
        val=0;
        prop_add=0;
    }
};
template <typename T, typename U>
struct Segtree{
    vector<U> seg;
    vector<T> v;
    U buildNode(int pos){
        return Node(v[pos], v[pos], 1);
    }
    U merge(U A, U B){
        if(A.len==-1) return B;
        if(B.len==-1) return A;
        return Node(A.sum+B.sum, B.len*A.sum + A.val + B.val, A.len+B.len);
    }
    void push(int i){
        if(seg[i].prop_reset){
            seg[2*i].prop_reset=true;
            seg[2*i].calc_reset();
            seg[2*i+1].prop_reset=true;
            seg[2*i+1].calc_reset();
            seg[i].prop_reset=false;
        }else{
            seg[2*i].prop_add += seg[i].prop_add;
            seg[2*i].calc_add(seg[i].prop_add);
            seg[2*i+1].prop_add += seg[i].prop_add;
            seg[2*i+1].calc_add(seg[i].prop_add);
            seg[i].prop_add=0;
        }
    }
    
    U _build(int i, int l, int r){
        if(l==r)
            return seg[i]=buildNode(l);
        else
            return seg[i] = merge(
                _build(2*i, l, (l+r)/2),
                _build(2*i+1, (l+r)/2+1, r)
            );
    }
    U _query(int i, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return U(-1, -1, -1);
        if(l!=r) push(i);
        if(ql <= l && r <= qr) return seg[i];
        return merge(
            _query(2*i, l, (l+r)/2, ql, qr),
            _query(2*i+1, (l+r)/2+1, r, ql, qr)
        );
    }
    Node _insert(int i, int l, int r, int pos){
        if(pos < l || r < pos) return seg[i];
        if(l==r) return seg[i] = buildNode(pos);
        return seg[i] = merge(
            _insert(2*i, l, (l+r)/2, pos),
            _insert(2*i+1, (l+r)/2+1, r, pos)
        );

    }
    Node _add_update(int i, int l, int r, int ql, int qr, T addend){
        if(qr < l || r < ql) return seg[i];
        if(l!=r) push(i);
        if(ql <= l && r <= qr){
            seg[i].prop_add+=addend;
            seg[i].calc_add(addend);
            return seg[i];
        }
        return seg[i] = merge(
            _add_update(2*i, l, (l+r)/2, ql, qr, addend),
            _add_update(2*i+1, (l+r)/2+1, r, ql, qr, addend)
        );
    }
    Node _reset_update(int i, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return seg[i];
        if(ql <= l && r <= qr){
            seg[i].prop_reset=true;
            seg[i].calc_reset();
            return seg[i];
        }
        push(i);
        return seg[i] = merge(
            _reset_update(2*i, l, (l+r)/2, ql, qr),
            _reset_update(2*i+1, (l+r)/2+1, r, ql, qr)
        );
    }
    void build(vector<T> _v){
        v = _v;
        seg.reserve(4*v.size());
        _build(1, 1, v.size()-1);
    }
    U query(int l, int r){
        U ans = _query(1, 1, v.size()-1, l+shift, r+shift);
        return ans;
    }
    void add_update(int l, int r, T addend){
        _add_update(1, 1, v.size()-1, l+shift, r+shift, addend);
    }
    void insert(int pos, T val){
        pos += shift;
        v[pos] = val;
        _insert(1, 1, v.size()-1, pos);
    }
    void add(int pos, T increment){
        insert(pos, v[pos+shift]+increment);
    }
    void reset(){
        _reset_update(1, 1, v.size()-1, 1, v.size()-1);
    }
};
int main(){
    int N;
    cin >> N;
    vector<int> v(2*N+10, 0);
    shift=N+3;
    Segtree<int, Node> S;
    S.build(v);
    
    /*
    int Q;
    cin >> Q;
    while(Q--){
        int t;
        cin >> t;
        if(t==0){
            int a, b;
            cin >> a >> b;
            Node ans = S.query(a, b);
            printf("sum:%d  val:%d\n", ans.sum, ans.val);
        }else if(t==1){
            int i, val;
            cin >> i >> val;
            S.insert(i, val);
        }else if(t==2){
            int l, r, add;
            cin >> l >> r >> add;
            S.add_update(l, r, add);
        }else if(t==3){
            S.reset();
        }
    }
    */

    map<int, vector<int>> indices;

    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        indices[t].push_back(i+1);
    }

    const bool DEBUG = true;
    ll ans=0;
    for(auto &[key, ids] : indices){
        if(DEBUG) printf("BARVA %d\n", key);

        //vstavi do prvega indexa
        int first = ids[0];
        if(DEBUG) printf("Vstavljam (%d)-(%d)\n", -(first-1), 0);
        S.add_update(-(first-1), 0, 1);

        for(int i=0;i<ids.size();i++){
            int id = ids[i];
            int cumSum = 2*(i+1) - id;

            if(DEBUG) printf("index %d | cs %d\n", id, cumSum);

            int next = i==(ids.size()-1) ? N : ids[i+1]-1;
            //poizvedi
            ll blockLength = next-id+1;

            if(DEBUG) printf("Block from %d to %d\n", id, next);

            Node primary = S.query(cumSum-blockLength, cumSum-1);
            if(DEBUG) printf("Primary block query (%d %d) yields %lld\n", cumSum-blockLength, cumSum-1, primary.val);

            Node secondary = S.query(-N, cumSum-blockLength-1);
            if(DEBUG) printf("Secondary block query yields %lld\n", secondary.sum);

            ans += primary.val + blockLength*secondary.sum;

            //vstavi
            if(DEBUG) printf("Vstavljam (%d)-(%d)\n", cumSum-blockLength+1, cumSum);
            S.add_update(cumSum-blockLength+1, cumSum, 1);   
            
        }
        S.reset();
        if(DEBUG) printf("-------RESET------\n");
    }
    cout << ans << endl;
}