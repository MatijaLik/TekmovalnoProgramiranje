#include<bits/stdc++.h>
using namespace std;
#define limit 200500
typedef pair<int, int> pii;
struct FenwickTree{
    int tree[2*limit];
    FenwickTree(){clear();}
    void insert(int id, int val){
        while(id < 2*limit){
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
bool sortByRight(pii a, pii b){
    if(a.second != b.second) return a.second<b.second;
    return a.first>b.first;
}
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        return p.first*1000000007 + p.second;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<pii, int, hash_pair> ans1, ans2;
    int n;
    cin >> n;
    pii intervali[n];
    pii original[n];
    set<int> comp; unordered_map<int, int> compM;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        comp.insert(a);comp.insert(b);
        intervali[i] = make_pair(a, b);
    }
    int id = 1;
    for(auto e : comp) compM[e] = id++;
    for(int i =0; i < n; i++){
        intervali[i].first = compM[intervali[i].first];
        intervali[i].second = compM[intervali[i].second];
    }
    copy(intervali, intervali+n, original);
    sort(intervali, intervali+n, sortByRight);
    FenwickTree F;
    for(auto e : intervali){
        ans1[e] = F.rangeQuery(e.first, e.second);
        F.insert(e.first, 1);
    }
    F.clear();
    reverse(intervali, intervali+n);
    for(auto e : intervali){
        ans2[e] = F.rangeQuery(1, e.first);
        F.insert(e.first, 1);
    }
    for(auto e : original) cout << ans1[e] << " ";
    cout << endl;
    for(auto e : original) cout << ans2[e] << " ";
    cout << endl;
}
