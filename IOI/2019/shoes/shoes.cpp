/**
 * Author: MatijaL
 * Time: 2021-06-18 19:02:04
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


ll a[200500];
ll segtree[800500];

int left(int i){return 2*i;}
int right(int i){return 2*i+1;}
int mid(int l, int r){return (l+r)/2;}

int query(int i, int l, int r, int q){
    if(q < l or r < q) return 0;

    if(l==r) return segtree[i];
    int m = mid(l, r);
    return segtree[i] + query(left(i), l, m, q) + query(right(i), m+1, r, q);
}

void add(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return;
    if(ql <= l and r <= qr){
        segtree[i]++;
        return;
    }
    int m = mid(l, r);
    add(left(i), l, m, ql, qr);
    add(right(i), m+1, r, ql, qr);
    return;
}



ll count_swaps(vector<int> v){
    map<int, queue<int>> m;
    
    int n = v.size();
    int par[n];
    loop(i, n) par[i] = -1;

    loop(i, n){
        int e = v[i];
        if(m[-e].empty()){
            m[e].push(i);
        }else{
            par[m[-e].front()] = i;
            m[-e].pop();
        }
    }

    ll ans = 0;
    loop(i, n){
        if(par[i] == -1) continue;
        ans += par[i] - i - 1;
        if(v[i] > 0) ans++;
        ans -= query(1, 1, n, i);
        ans += query(1, 1, n, par[i]);

        //printf("length %d |  %d | %d\n", par[i] - i - 1, query(1, 1, n, i), query(1, 1, n, par[i]));

        add(1, 1, n, i+1, par[i]-1);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    cout << count_swaps(v) << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
