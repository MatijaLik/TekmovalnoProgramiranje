/**
 * Author: MatijaL
 * Time: 2021-04-15 17:18:56
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
 
 
#define DEBUG 0
 
 
#warning spremeni limit
#define limit 4200000
 
 
ll N, M, X, P, R;
 
struct Node{
    ll sum, mx;
 
    int propAdd = 0;
    bool propDouble = false;
    ll propSet = 0;
 
    int l, r;
    int size;
 
    Node * lkid = NULL;
    Node * rkid = NULL;
 
    Node(ll _l, ll _r){
        l = _l;
        r = _r;
    }
 
    Node(){};
};
 
 
int space = 0;
Node nodes[limit];
ll a[limit];
 
Node* root;
 
void build(int l, int r, Node * cur){
    cur->l = l;
    cur->r = r;
    cur->size = r-l+1;
 
    if(DEBUG) printf("building %d %d\n", l, r);
 
    if(l == r){
        cur->mx = a[l-1];
        cur->sum = a[l-1];
        return;
    }
 
    //narei otroka
    int m = (l+r)/2;
 
    space++;
    cur->lkid = &nodes[space];
    build(l, m, &nodes[space]);
    
 
    space++;
    cur->rkid = &nodes[space];
    build(m+1, r, &nodes[space]);
    
 
    //poracunaj
    cur->sum = cur->lkid->sum + cur->rkid->sum;
    cur->mx = max(cur->lkid->mx, cur->rkid->mx);
}
 
bool zaPropSpremni(Node * cur){
    return cur->propAdd or cur->propDouble or cur->propSet;
}
 
void prop(Node* cur){
    assert(!(cur->propAdd and cur->propDouble));
    if(cur->propAdd){
        cur->sum += cur->propAdd*cur->size;
        cur->mx += cur->propAdd;
 
        if(cur->lkid!=NULL) cur->lkid->propAdd += cur->propAdd;
        if(cur->rkid!=NULL) cur->rkid->propAdd += cur->propAdd;
 
        cur->propAdd = 0;
    }
 
    if(cur->propDouble){
        cur->sum *= 2;
        cur->mx *= 2;
 
        if(cur->lkid!=NULL) cur->lkid->propDouble = true;
        if(cur->rkid!=NULL) cur->rkid->propDouble = true;
 
 
        cur->propDouble = false;
    }
 
    if(cur->propSet){
        cur->sum = cur->propSet;
        cur->mx = cur->propSet;
 
        if(cur->lkid!=NULL) cur->lkid->propSet = cur->propSet;
        if(cur->rkid!=NULL) cur->rkid->propSet = cur->propSet;
 
        cur->propSet = 0;
    }
 
}
 
void recalc(Node * cur){
    ll sum = 0;
    ll mx = 0;
    
    Node * left = cur->lkid;
    Node * right = cur->rkid;
 
    if(left->propAdd){
        sum += left->sum + left->propAdd*left->size;
        mx = max(mx, left->mx + left->propAdd);
    }
    else if(left->propDouble){
        sum += left->sum * 2;
        mx = max(mx, left->mx*2);
    }
    else if(left->propSet){
        sum += left->propSet*left->size;
        mx = max(mx, left->propSet);
    }else{
        sum += left->sum;
        mx = max(mx, left->mx);
    }
 
    if(right->propAdd){
        sum += right->sum + right->propAdd*right->size;
        mx = max(mx, right->mx + right->propAdd);
    }
    else if(right->propDouble){
        sum += right->sum * 2;
        mx = max(mx, right->mx*2);
    }
    else if(right->propSet){
        sum += right->propSet*right->size;
        mx = max(mx, right->propSet);
    }else{
        sum += right->sum;
        mx = max(mx, right->mx);
    }
    
    cur->sum = sum;
    cur->mx = mx;
    
}
 
void qAdd(int val, int l, int r, int ql, int qr, Node * cur){
 
    //zunaj
    if(qr < l or r < ql) return;
 
    //v celoti not
    if(ql <= l and r <= qr){
        if(zaPropSpremni(cur)) prop(cur);
        cur->propAdd += val;
        return;
    };
 
    int m = (l+r)/2;
    qAdd(val, l, m, ql, qr, cur->lkid);
    qAdd(val, m+1, r, ql, qr, cur->rkid);
 
    recalc(cur);
}
 
void qDouble(int l, int r, int ql, int qr, Node * cur){
 
    //zunaj
    if(qr < l or r < ql) return;
 
    //v celoti not
    if(ql <= l and r <= qr){
        if(zaPropSpremni(cur)) prop(cur);
        cur->propDouble = true;
        return;
    };
 
    int m = (l+r)/2;
    qDouble(l, m, ql, qr, cur->lkid);
    qDouble(m+1, r, ql, qr, cur->rkid);
 
    recalc(cur);
}
 
void qSet(int val, int l, int r, int ql, int qr, Node * cur){
 
    //zunaj
    if(qr < l or r < ql) return;
 
    //v celoti not
    if(ql <= l and r <= qr){
        if(zaPropSpremni(cur)) prop(cur);
        cur->propSet += val;
        return;
    };
 
    int m = (l+r)/2;
    qSet(val, l, m, ql, qr, cur->lkid);
    qSet(val, m+1, r, ql, qr, cur->rkid);
 
    recalc(cur);
}
 
 
//vrne <max, vsota>
pair<ll, ll> qValue(int l, int r, int ql, int qr, Node * cur){
 
    prop(cur);
 
    //zunaj
    if(qr < l or r < ql) return mp(0, 0);
 
    //v celoti not
    if(ql <= l and r <= qr){
        return mp(cur->mx, cur->sum);
    }
 
    int m = (l+r)/2;
    pair<ll, double> a = qValue(l, m, ql, qr, cur->lkid);
    pair<ll, double> b = qValue(m+1, r, ql, qr, cur->rkid);
 
    return mp(max(a.fs, b.fs), a.sc+b.sc);
}
 
void printAll(Node * cur){
    prop(cur);
    if(cur->size == 1){
        cout << cur->sum << " ";
    }else{
        printAll(cur->lkid);
        printAll(cur->rkid);
        if(cur == root) cout << endl;
    }
}
 
 
 
void solve(){
 
    cin >> N >> M >> X >> P >> R;
    loop(i, N) cin >> a[i];
    
    
    loop(i, limit) nodes[i] = Node();
    root = &nodes[0];
    build(1, N, root);
 
    
    loop(i, M){
        //printAll(root);
        int L, D, C;
        cin >> L >> D >> C;
        pll res = qValue(1, N, L, D, root);
 
        ll MAX = res.fs;
        double AVG = ((double)res.sc) / (D-L+1);
 
        if(DEBUG) printf("MAX %lld | AVG %lf\n", MAX, AVG);
 
        //1. pogoj
        if(MAX < ((double) X )/ 2){
            if(DEBUG) printf("doubling\n");
            qDouble(1, N, L, D, root);
            continue;
        }
 
        //2. pogoj
        if(X < MAX){
            if(DEBUG) printf("set to %d\n", C);
            qSet(C, 1, N, L, D, root);
            continue;
        }
 
        //3.pogoj
        if(AVG < ((double) X )/ 2){
            if(DEBUG) printf("adding P = %lld\n", P);
            qAdd(P, 1, N, L, D, root);
            continue;
        }
 
        //sicer
        if(DEBUG) printf("adding R = %lld\n", R);
        qAdd(R, 1, N, L, D, root);
    }
 
    printAll(root);
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}