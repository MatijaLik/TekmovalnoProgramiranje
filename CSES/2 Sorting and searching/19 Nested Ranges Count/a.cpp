#include<bits/stdc++.h>
using namespace std;
#define limit 200500
 
//MergeTree
struct MergeTree{
    vector<int> a[6*limit];
    map<int, vector<int>> base;
    int mx;
    MergeTree(vector<int> l, vector<int> r, int _mx){
        mx = _mx;
        for(int i=0;i<l.size();i++) base[l[i]].push_back(r[i]);
        _build(1, 1, mx);
    }
    void _build(int node, int L, int R){
        if(L==R){a[node] = base[L]; sort(a[node].begin(), a[node].end());return;}
        int m = (L+R)/2;
        _build(2*node, L, m);
        _build(2*node+1, m+1, R);
        merge(a[2*node].begin(), a[2*node].end(), a[2*node+1].begin(), a[2*node+1].end(), back_inserter(a[node]));
    }
    int queryInside(int QL, int QR){return _query(1, 1, mx, QL, QR, 0);}
    int queryOver(int QL, int QR){return _query(1, 1, mx, 1, QL, QR);}
    int _query(int node, int L, int R, int QL, int QR, int type){
        if(QR < L or R < QL) return 0;
        if(QL <= L and R <= QR){
            if(type) return distance(lower_bound(a[node].begin(), a[node].end(), type), a[node].end());
            else return distance(a[node].begin(), upper_bound(a[node].begin(), a[node].end(), QR));
        }
        int m = (L+R)/2;
        return _query(2*node, L, m, QL, QR, type) + _query(2*node+1, m+1, R, QL, QR, type);
    }
};
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    set<int> comp; unordered_map<int, int> compM;
    for(int i=0;i<n;i++){
        cin >> l[i];
        cin >> r[i];
        comp.insert(l[i]);
        comp.insert(r[i]);
    }
    int id=1;
    for(auto e:comp) compM[e] = id++;
    for(int i=0;i<n;i++) {l[i] = compM[l[i]]; r[i] = compM[r[i]];}
    MergeTree S(l, r, comp.size());
    //SORTIRAJ SI QUERIJE
    for(int i=0;i<n;i++) cout << S.queryInside(l[i], r[i])-1 << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << S.queryOver(l[i], r[i])-1 << " ";
    cout << endl;
    return 0;
}
