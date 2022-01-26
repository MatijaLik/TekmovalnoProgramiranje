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

struct Kandidat{
    int V, W, X;
    Kandidat(int _V, int  _W,int _X): V(_V), W(_W), X(_X){}
};

void solve(){
    int N, K;
    cin >> K >> N;
    vector<Kandidat> v;
    v.pb(Kandidat(0,0,0));
    loop(i, N){
        int a, b,c;
        cin >> a >> b >> c;
        v.pb(Kandidat(a, b, c));
    }
    assert(N<=100);
    ll DP[200][3000];
    memset(DP, 0, sizeof DP);
    FOR(i, 1, N){
        FOR(rem, 0, K){
            FOR(x, 0, v[i].X){
                if(x*v[i].W > rem) break; 
                DP[i][rem] = max(DP[i][rem], x*v[i].V + DP[i-1][rem-x*v[i].W]);
            }
            //cout << DP[i][rem] << " ";
        }
    }
    cout << DP[N][K] << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}