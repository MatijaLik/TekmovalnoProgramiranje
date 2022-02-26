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


map<pll, ll> color;
vector<pll> edges;
set<pll> pairs;
#define DEBUG 0

set<int> lasko(set<int> a, set<int> b){
    set<int> ans;
    for(auto e : a)ans.insert(e);
    for(auto e : b)ans.insert(e);
    return ans;
}

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

pair<set<int>, bool> dfs1(int node, int prev, int goal){
    if(node==goal) return mp(set<int>(), 1);

    for(auto e : sosedi[node]){
        if(e==prev) continue;
        int cl = color[mp(node, e)];
        pair<set<int>, bool> p = dfs1(e, node, goal);
        if(p.sc){
            p.fs.insert(cl);
            return mp(p.fs, 1);
        }
    }

    return mp(set<int>(), 0);
}

bool verify(int a, int b){
    set<int> s = dfs1(a, a, b).fs;
    if(s.size()==2)return 1;
    else return 0;
}


void solve(){
    //m=1
    cin >> N >> M >> K;
    loop(i, N-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
        edges.pb(mp(a, b));
    }
    ll ans = 0;
    if(N<=15&&K==2){
        loop(i, M){
            int a, b;
            cin >> a >> b;
            pairs.insert(mp(a, b));
        }
        
        FOR(mask, 0, (1<<(N-1))-1){
            //pobarvaj
            for(int i=0;i<edges.size();i++){
                int a = edges[i].fs;
                int b = edges[i].sc;
                if(mask&(1<<i)){
                    color[mp(a, b)]=1;
                    color[mp(b, a)]=1;
                }
                else{
                    color[mp(a, b)]=0;
                    color[mp(b, a)]=0;
                }
            }

            //preveri
            bool gud = true;
            for(auto p : pairs){
                gud &= verify(p.fs, p.sc);
            }
            if(gud) {
                ans++;
                if(DEBUG) printf("Mask %d\n", mask);
            }

        }
    }else{
        ans=1;
        int lengthSum = 0;
        loop(i, M){
            int a, b;
            cin >> a >> b;
            int len = dist(a, b);
            if(DEBUG){
                printf("length is %d\n", len);
            }
            ans = mul(ans,sub(binpow(K, len),K));
            lengthSum+=len;
        }
        
        ans = mul(ans, binpow(K, (N-1)-lengthSum));
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