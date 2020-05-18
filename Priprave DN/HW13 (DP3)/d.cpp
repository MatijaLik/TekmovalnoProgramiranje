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
#define debug(x) cout << "# " << x << endl

#define nlimit 4010
#define klimit 810

int grid[nlimit][nlimit];
ll rs[nlimit][nlimit];
int N, K;

ll erect(int ti, int tj, int bi, int bj){
    ll sum = 0;
    sum += rs[bi][bj];

    sum -= rs[bi][tj-1];
    sum -= rs[ti-1][bj];

    //dvojno stetje
    sum += rs[ti-1][tj-1];

    return sum;
}

ll memo[nlimit][klimit];


ll dp(int n, int k){
    if(memo[n][k] != -1) return memo[n][k];
    if(k == 0) return 0;
    if(n <= k) return -inf;

    ll best = 0;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    K--;
    FOR(i, 1, N)FOR(j, 1, N) cin >> grid[i][j];

    //naredi rolling sum
    FOR(i, 1, N)FOR(j, 1, N) rs[i][j] = grid[i][j] + rs[i-1][j] + rs[i][j-1] - rs[i-1][j-1];

    //pripravi za dp
    loop(i, nlimit)loop(j, klimit) memo[i][j] = -1;


    ll totatCost = erect(1, 1, N, N)/2;

    return 0;
}