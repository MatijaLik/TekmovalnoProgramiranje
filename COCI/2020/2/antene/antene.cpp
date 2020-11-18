/**
 * Author: MatijaL
 * Time: 2020-11-14 15:23:46
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

#define limit 1100

ll N , M;
ll parent[limit];
ll sz[limit];

vector<pll> antene;

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

ll un(ll x, ll y){
    x = find(x);
    y = find(y);
    if(sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    ll t = sz[x];
    sz[x] += sz[y];
    return sz[y]*t;
}

void solve(){
    cin >> N;

    loop(i, N){
        ll x, y;
        cin >> x >> y;
        antene.pb(mp(x, y));
    }

    loop(i, N) parent[i] = i;
    loop(i, N) sz[i] = 1;

    priority_queue<pair<long double, pll>> q;

    //Zracuna razdalje med vsemi pari anten
    loop(i, N)loop(j, N){
        if(i >= j) continue;
        pll a1 = antene[i];
        pll a2 = antene[j];

        long double dx = abs(a1.fs - a2.fs);
        long double dy = abs(a1.sc - a2.sc);

        long double dist = sqrt(dx*dx + dy*dy);

        q.push(mp(-dist/2, mp(i, j)));
    }

    ll moves = 0;
    long double best = 0;
    while(moves < N-1){
        pair<long double, pll> p = q.top();
        q.pop();
        long double w = -p.fs;
        ll a = p.sc.fs;
        ll b = p.sc.sc;

        if(find(a)==find(b))continue;
        un(a,b);
        moves++;
        best = max(best, w);
        //cout << "----" << endl;
        //cout << a << " " << b << endl;
        //cout << w << endl;
    }
    printf("%.10Lf\n", best);

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
