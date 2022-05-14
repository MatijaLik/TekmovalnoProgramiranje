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

//Li Chao Tree

const int N_LIMIT=400010;

struct Line{
    ll k, n;
    Line(){};
    Line(ll _k, ll _n): k(_k), n(_n){};
    ll operator[](ll x){
        return k*x+n;
    }
};

struct LiChaoTree{
    Line a[4*N_LIMIT];
    LiChaoTree(){
        FOR(i, 1, 4*N_LIMIT-1) a[i]=Line(-inf,-inf*1LL*inf);
    };
    void reset(){
        FOR(i, 1, 4*N_LIMIT-1) a[i]=Line(-inf,-inf*1LL*inf);
    };
    void add_line(Line L){
        insert(L, 1, 1, N_LIMIT);
    }
    void insert(Line nw, int i, int l, int r){
        int m = (l+r)/2;

        bool left = nw[l] > a[i][l];
        bool mid = nw[m] >= a[i][m];

        if(mid) swap(a[i], nw);
        if(l==r) return;

        if(mid!=left)
            insert(nw, 2*i, l, m);
        else
            insert(nw, 2*i+1, m+1, r);
    }

    ll best_line(ll x){
        return query(x, 1, 1, N_LIMIT)[x];
    }

    Line query(ll x, int i, int l, int r){
        int m = (l+r)/2;
        Line cur = a[i];
        if(l==r) return cur;
        Line oth;
        if(l<=m)
            oth = query(x, 2*i, l, m);
        else 
            oth = query(x, 2*i+1, m+1, r);

        return cur[x]>=oth[x] ? cur : oth;
    }
};

void solve(){
    int N;
    cin >> N;
    
    vector<ll> a(N+1);
    ll cum[N+1];
    cum[0]=0;

    ll base=0;
    FOR(i, 1, N) {cin >> a[i]; cum[i]=cum[i-1]+a[i]; base+=a[i]*i;}
    ll ANS=base;

    LiChaoTree lines=LiChaoTree();

    //V desno
    lines.add_line(Line(a[1], cum[1]-a[1]*1));

    FOR(j, 2, N){
        ll best=-cum[j]+lines.best_line(j);
        //printf("r %lld -> best %lld\n", j, best);
        ANS = max(ANS, base+best);
        lines.add_line(Line(a[j], cum[j]-a[j]*j));
    }

    lines.reset();

    //V levo
    ll rcum[N+2];
    rcum[N+1]=0;
    for(int i=N;i>=1;i--) rcum[i] = a[i] + rcum[i+1];

    lines.add_line(Line(a[N], -rcum[N]-a[N]*N));
    for(ll j=N-1;j>=1;j--){
        ll best = rcum[j] + lines.best_line(j);
        //printf("l %lld -> best %lld\n", j, best);
        ANS=max(ANS, base+best);
        lines.add_line(Line(a[j], -rcum[j]-a[j]*j));
    }
    cout << ANS << endl;
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();   
}