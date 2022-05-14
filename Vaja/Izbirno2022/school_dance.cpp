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

const int limit = 505;
vector<int> sosedi[limit];


vector<int> mt;
vector<int> visited;


bool try_kuhn(int v){
    if(visited[v]){
        return false;
    }
    visited[v] = true;
    for(auto e :sosedi[v]){
        if(mt[e]==-1 or try_kuhn(mt[e])){
            mt[e]=v;
            return true;
        }
    }
    return false;
}

void solve(){
    int N, M, K;
    cin >> N >> M >> K;
    loop(i, K){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
    }

    visited.assign(N+2, 0);
    mt.assign(M+2, -1);

    FOR(i, 1, N){
        visited.assign(N+2, 0);
        try_kuhn(i);
    }

    int cnt=0;
    for(auto e : mt){
        if(e>0) cnt++;
    }
    cout << cnt << endl;
    FOR(i, 1, M){
        if(mt[i]>0){
            cout << mt[i] << " " << i << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();   
}