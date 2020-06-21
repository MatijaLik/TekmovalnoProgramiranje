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
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define dlimit 10010
#define nlimit 1010
#define qlimit 110

ll tree[4*dlimit];

ll left(ll i){ return (2*i);}
ll right(ll i){ return (2*i+1);}


void update(ll q, ll l, ll r, ll i){
    if(q < l or q > r) return; // zunaj
    //if is contained
    ll mid = (l+r)/2;
    if(l <= q and q <= r){
        //printf("added %d at %d %d\n", id, l, r);
        if(l==r) tree[i] = 1-tree[i];
        else{
            update(q, l, mid, left(i));
            update(q, mid+1, r, right(i));
            tree[i] = tree[left(i)] + tree[right(i)];
        }
        return;
    }
}

ll query(ll ql, ll qr, ll l, ll r, ll i){
    //printf("looking for %d at %d %d\n", q, l, r);
    ll res = 0;
    ll mid = (l+r)/2;
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return tree[i];
    return query(ql, qr, l, mid, left(i)) + query(ql, qr, mid+1, r, right(i));
    return res;
}
void clearTree(){
    memset(tree, 0, sizeof tree);
}


ll N, M, D, Q;
vector<ll> sosedi[nlimit];
ll vrednost[nlimit];
pll ti[nlimit];
ll tres[nlimit];
vector<ll>moznosti[qlimit];
set<ll> moznostiS[qlimit];

ll memo[qlimit][nlimit];


ll dp(ll time, ll node){
    //printf("dp %d %d\n", time, node);
    if(memo[time][node]!=-1) return memo[time][node];
    if(time == Q) return memo[time][node] = vrednost[node];
    ll best = -1;
    if(moznostiS[time].count(node))best = max(best, dp(time+1, node));// ja ostajem
    //printf("dp %d %d, sosedi\n", time, node);
    for(auto sosed : sosedi[node]){//ti odlazis
        if(moznostiS[time].count(sosed)){
            best = max(best, dp(time+1, sosed));
        }
    }
    if(best == -1) return memo[time][node] = -inf;//nikamor za it
    return memo[time][node] = best + vrednost[node];//daj najjaco resitev
}


int main(){
    cin >> N >> M >> D >> Q;
    loop(i, M){//hodniki
        ll a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    FOR(i,1, N){
        ll v, a , b;
        cin >> v >> a >> b;
        vrednost[i] = v;
        ti[i] = mp(a,b);
        ll len = b-a+1;
        if(len%2==0) tres[i] = len/2;
        else tres[i] = (len/2)+1; 
    }
    loop(i, Q){
        //cout << "#######" << endl;
        ll amnt;
        cin >> amnt;
        loop(e, amnt){
            ll sensor;
            cin >> sensor;
            //printf("adding sensor %d\n", sensor);
            update(sensor, 1, dlimit, 1);
        }
        FOR(sef, 1, N){
            ll a, b;
            a = ti[sef].fs;
            b = ti[sef].sc;
            ll res = query(a, b, 1, dlimit, 1);
            if(res >= tres[sef]) {
                moznosti[i].pb(sef);//vir napake (mogoce forward feed ni ok);
                moznostiS[i].insert(sef);
            }
        }
    }


    //pripravi na double penetration
    loop(i, qlimit)loop(j, nlimit) memo[i][j] = -1;


    ll best = 0;
    for(auto zacetek : moznosti[0]){
        best = max(best, dp(1, zacetek));
    }
    cout << best << endl;


}