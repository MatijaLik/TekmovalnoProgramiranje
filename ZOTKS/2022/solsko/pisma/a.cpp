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
#define inf 1000000000
#define mod 1000000007
#define nlimit 200
void solve(){
    int in[nlimit];
    vector<pll> otroci[nlimit];
    ll casMin[nlimit];
    ll casMax[nlimit];
    memset(in, 0, sizeof in); 
    memset(casMax, 0, sizeof casMax);
    loop(i, nlimit) casMin[i] = inf;
    int N, M;
    cin >> N >> M;
    loop(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        in[b]++;
        otroci[a].pb(mp(b, c));
    }
    assert(in[1]==0);
    queue<int> q;
    q.push(1);
    ll ans = 0;
    while(!q.empty()){
        int el = q.front();
        q.pop();
        //printf("%d %d\n", el, cas[el]);
        for(auto e : otroci[el]){
            int node = e.fs;
            ll time = e.sc;
            in[node]--;
            casMax[node] = max(casMax[node], casMax[el]+time);
            casMin[node] = min(casMin[node], casMax[el]+time);
            if(in[node]==0) q.push(node);
        }
    }
    FOR(n, 2, N){
        //printf("%d %d\n", casMin[n], casMax[n]);
        ans += casMax[n] - casMin[n];
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}