
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 400030

ll N, K, Q;
vector<ll> tree[2*limit];
ll ps[limit];   

ll left(ll i){ return (2*i+1);}
ll right(ll i){ return (2*i+2);}


void insert(ll ql, ll qr, ll l, ll r, ll i, ll id){
    //if is contained
    ll mid = (l+r)/2;
    if(ql <= l and r <= qr){
        //printf("added %d at %d %d\n", id, l, r);
        tree[i].pb(id);
        return;
    }
    if(ql <= mid and l <=qr){
        insert(ql, qr, l, mid, left(i), id);
    }
    if(ql <= r and mid+1<= qr){
        insert(ql, qr, mid+1, r, right(i), id);
    }
}

ll query(ll q, ll l, ll r, ll i){
    //printf("looking for %d at %d %d\n", q, l, r);
    ll res = 0;
    ll mid = (l+r)/2;
    res += tree[i].size();
    if(i >= limit) return res;
    if(q <= mid) res += query(q, l, mid, left(i));
    if(q > mid) res += query(q, (mid)+1, r, right(i));
    return res;
}

int main(){
    cin >> N >> K >> Q;
    loop(i, N){
        ll a, b;
        cin >> a >> b;
        
        insert(a, b, 1, limit, 0, i);
        
    }
    FOR(i, 1, limit){
        ps[i] = ps[i-1];
        if(query(i, 1, limit, 0) >= K){
            ps[i]++;
        }
    }
    loop(i, Q){
        ll a, b;
        cin >> a >> b;
        cout << ps[b]-ps[a-1] << endl;
    }

}