/**
 * Author: MatijaL
 * Time: 2020-11-18 10:08:44
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

void solve(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> v(N+1);
    loop(i, N) cin >> v[i+1];
    vector<pair<pll, ll>> queries(M+1);
    loop(i, M){
        ll l, r, d;
        cin >> l >> r >> d;
        queries[i+1] = mp(mp(l, r), d);
    }

    ll upq[M+1];
    ll downq[M+1];

    memset(upq, 0, sizeof upq);
    memset(downq, 0, sizeof downq);

    loop(i, K){
        ll x, y;
        cin >> x >> y;
        upq[x]++;
        downq[y]++;
    }

    /*
    loop(i, M+1) cout << upq[i] << " ";
    cout << endl;
    loop(i, M+1) cout << downq[i] << " ";
    cout << endl;
    */


    ll cumq = 0;
    ll upv[N+1];
    ll downv[N+1];

    memset(upv, 0, sizeof upv);
    memset(downv, 0, sizeof downv);

    loop(i, M){
        cumq += upq[i+1];
        pll p  = queries[i+1].fs;
        ll d = queries[i+1].sc;
        //printf("%lld -> add %lld at | %lld - %lld\n", i+1, cumq*d, p.fs, p.sc);
        upv[p.fs] += cumq*d;
        downv[p.sc] += cumq*d;
        cumq -= downq[i+1];
    }

    /*
    loop(i, N+1) cout << upv[i] << " ";
    cout << endl;
    loop(i, N+1) cout << downv[i] << " ";
    cout << endl;
    */


    ll cum = 0;
    loop(i, N){
        cum += upv[i+1];
        v[i+1] += cum;
        cum -= downv[i+1];
    }

    FOR(i, 1, N) cout << v[i] << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
