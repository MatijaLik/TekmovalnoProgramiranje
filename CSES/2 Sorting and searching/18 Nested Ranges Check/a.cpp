#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define limit 200100
typedef pair<int, int> pii;
struct FenwickTree{
    int tree[2*limit];
    int sz;
    FenwickTree(int _sz){clear();sz=_sz;}
    void insert(int id, int val){
        while(id < sz+100){
            tree[id] += val;
            id += id & -id;
        }
    }
    int query(int id){
        int ans = 0;
        while(id > 0){
            ans += tree[id];
            id -= id & -id;
        }
        return ans;
    }
    int rangeQuery(int l, int r){
        return query(r) - query(l-1);
    }
    void clear(){
        memset(tree, 0, sizeof tree);
    }
};
bool sortByRight(pii& a, pii & b){
    if(a.second != b.second) return a.second<b.second;
    return a.first>b.first;
}

inline long long hsh(pii p){return 200100*((long long) p.first) + (long long) p.second;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int, int> ans1, ans2;
    int n;
    cin >> n;
    ans1.reserve(2*n);
    ans2.reserve(2*n);
    pii intervali[n];
    pii original[n];
    unordered_map<long long, int> compM;
    compM.reserve(2*n);
    int comp[2*n];
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        comp[2*i] = a; comp[2*i+1] = b;
        intervali[i] = make_pair(a, b);
    }
    sort(comp, comp+2*n);
    int id = 1;
    for(int i = 0; i < 2*n;i++){
        if(i == 0 || (comp[i] != comp[i-1])) compM[comp[i]] = id++;
    } 
    for(int i =0; i < n; i++){
        intervali[i].first = compM[intervali[i].first];
        intervali[i].second = compM[intervali[i].second];
    }
    copy(intervali, intervali+n, original);
    sort(intervali, intervali+n, sortByRight);
    FenwickTree F(id);
    for(int i = 0; i < n; i++){
        pii e = intervali[i];
        ans1[hsh(e)] = F.rangeQuery(e.first, e.second);
        F.insert(e.first, 1);
    }
    F.clear();
    for(int i = n-1; i>=0;i--){
        pii e = intervali[i];
        ans2[hsh(e)] = F.rangeQuery(1, e.first);
        F.insert(e.first, 1);
    }
    for(auto e : original) cout << (ans1[hsh(e)] ? 1 : 0) << " ";
    cout << endl;
    for(auto e : original) cout << (ans2[hsh(e)] ? 1 : 0) << " ";
    cout << endl;
}
