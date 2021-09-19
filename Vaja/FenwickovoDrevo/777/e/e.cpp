/**
 * Author: MatijaL
 * Time: 2021-06-20 12:38:54
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



struct SegTree{
    ll seg[800500];

    SegTree(){
        memset(seg, 0, sizeof seg);
    }

    int left(int i){return 2*i;}
    int right(int i){return 2*i+1;}
    int mid(int l, int r){return (l+r)/2;}

    void insert(int i, int l, int r, int q, ll val){
        if(q < l or r < q) return;
        //printf("insert %d %d %d %d %lld\n", i, l, r, q, val);
        seg[i] = max(seg[i], val);
        if(l==r) return;
        int m = mid(l, r);
        insert(left(i), l, m, q, val);
        insert(right(i), m+1, r, q, val);
        return;
    }

    ll QUERY(int i, int l, int r, int ql, int qr){
        if(r < ql or qr < l) return 0;
        if(ql <= l and r <= qr) return seg[i];
        int m = mid(l, r);
        return max(
            QUERY(left(i), l, m, ql, qr),
            QUERY(right(i), m+1, r, ql, qr)
        );
    }
};


//pari bodo tkole : <outer, inner> 
/*
bool custom_sort(const pair<int, int> a, const pair<int, int> b){
    if()
}*/


void solve(){
    int n;
    vector<pair<pll, ll>> v;


    //jebeni compression spet
    set<ll> compS;
    map<ll, ll> comp;

    cin >> n;
    loop(i, n){
        ll a, b, h;
        cin >> a >> b >> h;
        compS.insert(a);
        compS.insert(b);
        v.pb(mp(mp(b, a), h));
    }

    //compression
    ll id = 1;
    for(auto e : compS) comp[e] = id++;

    sort(all(v));
    SegTree s = SegTree();

    for(auto e : v){
        ll a, b, h;

        a = e.fs.sc;
        b = e.fs.fs;
        h = e.sc;

        a = comp[a];
        b = comp[b];
        ll maxH = s.QUERY(1, 1, 200500, a+1, b);

        //printf("%lld %lld | maxH %lld | h %lld\n", a,b, maxH, h);
        s.insert(1, 1, 200500, b, maxH+h); 
    }



    cout << s.seg[1] << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
