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

const int MOD = 1000000007;
#define Nlimit 70

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}
int N, M, K;
vector<int> sosedi[Nlimit];

int dfs(int depth, int cur, int prev, int goal){
    if(cur==goal)return depth;
    for(auto e : sosedi[cur]){
        if(e==prev)continue;
        int res = dfs(depth+1, e, cur, goal);
        if(res) return res;
    }
    return 0;
}

int dist(int a, int b){
    return dfs(0, a, a, b);
}
#define DEBUG 0
void solve(){
    //m=1
    cin >> N >> M >> K;
    loop(i, N-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    assert(M==1);
    int a, b;
    cin >> a >> b;
    int len = dist(a, b);

    if(DEBUG){
        printf("length is %d\n", len);
    }
    
    ll ans = 1;
    ans = mul(ans,sub(binpow(K, len),K));
    ans = mul(ans, binpow(K, (N-1)-len));
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}