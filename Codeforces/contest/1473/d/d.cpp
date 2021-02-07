/**
 * Author: MatijaL
 * Time: 2021-01-14 15:35:19
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
    int dif;
    int bot, top;
    Node(int a, int c, int d){
        dif = a;
        bot = c;
        top = d;
    }
    Node(){
        dif = 0;
        bot = 0;
        top = 0;
    }

};
Node mergeNode(Node a, Node b){
    int dif = a.dif+b.dif;
    int bot = min(a.bot, b.bot+a.dif);
    int top = max(a.top, b.top+a.dif);
    return Node(dif, bot, top);
}
#define limit 200100
Node segtree[4*limit];
int N, Q;
int left(int i){return 2*i;}
int right(int i){return (2*i)+1;};
int mid(int l, int r){
    return (l+r)/2;
}
string s;
void build(int i, int l, int r){

    if(l == r){
        char c = s[l-1];
        Node node = Node(0,0,0);
        if(c == '-') node = Node(-1, -1, 0);
        else node = Node(1, 0, 1);
        segtree[i] = node;
    }else{
        int m = mid(l, r);
        build(left(i), l, m);
        build(right(i), m+1, r);
        segtree[i] = mergeNode(segtree[left(i)], segtree[right(i)]);
    }
}
Node query(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return Node();
    //celo not
    if(ql <= l and r <= qr) return segtree[i];
    
    int m = mid(l, r);
    return mergeNode(query(left(i), l, m, ql, qr), query(right(i), m+1, r, ql, qr));
}

void printNode(Node n){
    printf("%d %d %d\n", n.dif, n.bot, n.top);
}
void solve(){
    cin >> N >> Q;
    cin >> s;
    build(1, 1, N);
    FOR(i, 1, 2*N){
        //printf("%d -> ", i);
        //printNode(segtree[i]);
    }
    loop(i, Q){

        int a, b;
        cin >> a >> b;
        Node left = query(1, 1, N, 1, a-1);
        Node right = query(1, 1, N, b+1, N);

        Node ans = mergeNode(left, right);
        //printf("%d %d %d\n", ans.dif, ans.bot, ans.top);
        cout << ans.top - ans.bot + 1 << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
