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
#define inf 9223372036854775000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 200010

ll N, M;
ll nums[limit];
ll seg[4*limit];
ll lazy[4*limit];

ll MID(ll a, ll b){ return (a+b)/2;}

ll build(ll l, ll r, ll i){
    ll mid = MID(l, r);
    if(l == r) return seg[i] = nums[l]; // list
    return seg[i] = min(
        build(l, mid, 2*i),
        build(mid+1, r, 2*i + 1)
    );
}

ll getRange(ll ql, ll qr, ll l, ll r, ll i){
    if(lazy[i] != 0){
        seg[i] += lazy[i];
        if(l != r){// posreduj navzdol
            lazy[i*2] += lazy[i]; 
            lazy[i*2 + 1] += lazy[i]; 
        }
        lazy[i] = 0;
    }

    //out of range
    if(qr < l or r < ql) return inf;

    //v celoti notri
    if(ql <= l and r <= qr) return seg[i];

    //malo sem pa malo taj
    ll mid = MID(l, r);
    return min(
        getRange(ql, qr, l, mid, 2*i),
        getRange(ql, qr, mid+1, r, 2*i+1)
    );
}

void update(ll ql, ll qr, ll l, ll r, ll i, ll diff){

    if(lazy[i] != 0){
        seg[i] += lazy[i];
        if(l != r){// posreduj navzdol
            lazy[i*2] += lazy[i]; 
            lazy[i*2 + 1] += lazy[i]; 
        }
        lazy[i] = 0;
    }

    if(qr < l or r < ql) return;//out of range

    if(ql <= l and r <= qr){
        seg[i] += diff; // v celoti notri
        if(l!=r){
            // ce ni list, poslji update naprej
            lazy[2*i] += diff;
            lazy[2*i+1] += diff;
        }
        return;
    }

    ll mid = MID(l, r);
    update(ql, qr, l, mid, 2*i, diff);
    update(ql, qr, mid+1, r, 2*i + 1, diff);
    seg[i] = min(seg[2*i], seg[2*i+1]);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    loop(i,N) cin >> nums[i+1];
    cin >> M;
    build(1, N, 1);
    /*
    loop(i, 2*N){
        cout << seg[i] << " ";
    }cout << endl;*/
    loop(q, M){
        vector<ll> in;
        while(1){
            ll temp;
            cin >> temp;
            in.pb(temp);
            if(cin.peek()=='\n') break;
        }
        in[0]++;
        in[1]++;
        if(in.size() == 2){
            if(in[0] <= in[1]) cout << getRange(in[0], in[1], 1, N, 1) << endl;
            else cout << min(
                getRange(1, in[1], 1, N, 1),
                getRange(in[0], N, 1, N, 1)
            ) << endl;
        }else{
            if(in[0] <= in[1]) update(in[0], in[1], 1, N, 1, in[2]);
            else{
                update(1, in[1], 1, N, 1, in[2]);
                update(in[0], N, 1, N, 1, in[2]);
            }
        }
    }
}