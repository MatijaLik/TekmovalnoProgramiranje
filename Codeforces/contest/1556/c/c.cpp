/**
 * Author: MatijaL
 * Time: 2021-08-29 16:35:02
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
int n;
int A[4000];
const int limit = 4000;
ll neto[limit], dol[limit], gor[limit], sz[limit]; 

int left(int i) {return 2*i;}
int right(int i) {return 2*i+1;};
int mid(int l, int r){return (l+r)/2;}

const bool DEBUG = 0;

void build(int i, int l, int r){
    sz[i] = r-l+1;
    if(l==r){
        if(l%2==1){
            neto[i] = A[l];
            gor[i] = A[l];
        }else{
            neto[i] = -A[l];
            dol[i] = A[l];
        } if(DEBUG)   printf("build %d-%d, size %lld, neto %lld, gor %lld, dol %lld\n",
                l, r, sz[i], neto[i], gor[i], dol[i]);
        return;
    }
    int m = mid(l, r);
    build(left(i), l, m);
    build(right(i), m+1, r);


    neto[i] = neto[left(i)] + neto[right(i)];
    dol[i] = max(dol[left(i)],- neto[left(i)] + dol[right(i)]);
    gor[i] = max(gor[left(i)], neto[left(i)] + gor[right(i)]);

    if(DEBUG)
        printf("build %d-%d, size %lld, neto %lld, gor %lld, dol %lld\n",
                l, r, sz[i], neto[i], gor[i], dol[i]);
    return;
}


pair<pll, pll> query(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return mp(mp(0,0), mp(0,0));
    if(ql <= l and r <= qr) return mp(mp(sz[i], neto[i]), mp(gor[i], dol[i]));

    int m = mid(l, r);
    pair<pll, pll> p = query(left(i), l, m, ql, qr); 
    pair<pll, pll> q = query(right(i), m+1, r, ql, qr); 

    return mp(
            mp(p.fs.fs + q.fs.fs,
                p.fs.sc + q.fs.sc),
            mp(
                max(p.sc.fs, p.fs.sc + q.sc.fs),
                max(p.sc.sc, -p.fs.sc + q.sc.sc))
            );
}
void solve(){
    cin >> n;
    loop(i, n) cin >> A[i+1];
    build(1, 1, n);

    ll ans = 0;
    FOR(L, 1, n-1){
        FOR(R, L, n-1){
            if(L%2==0) continue;
            if(R%2==0) continue;
            pair<pll, pll> p = query(1, 1, n, L, R);
            if(DEBUG)
                printf("query %d-%d, sz %d, neto %d, gor %d, dol %d\n",L, R,  p.fs.fs, p.fs.sc, p.sc.fs, p.sc.sc);
            if(p.sc.sc > 0) continue;
            if(L == R){
                if(DEBUG)
                    printf("L == R| + %lld\n", min(A[L], A[R+1]));
                ans += min(A[L], A[R+1]);
            }else{
                pair<pll, pll> q = query(1, 1, n, L+1, R);
                ll lmp = A[L] - q.sc.sc;
                ll neto = p.fs.sc;
                ll visina = max(0LL, neto - A[R+1]);
                if(DEBUG)
                    printf("lmp je %d | visina %d\n", lmp, visina);
                if(lmp >= visina) ans += lmp - visina + 1;
            }


        }
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
