/**
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
vector<int> sosedi[200100];
int leaves = 0;

vector<int> listi;
void dfs(int node, int prev){
    int cnt = 0;
    for(auto e : sosedi[node]){
        if(e == prev) continue;
        cnt++;
        dfs(e, node);
    }
    if(cnt == 0)
   {
       leaves++;
       listi.pb(node);
   } 
    return;
}



int myrandom (int i) { return std::rand()%i;}

void solve(){

    std::srand ( unsigned ( std::time(0) ) );

    int n;
    cin >> n;
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    //najdi neki spodobni root
    int root = 1;
    while(sosedi[root].size() == 1) root++;
    dfs(root, 0);

    int ans = leaves/2 + leaves %2;
    cout << ans << endl;
    random_shuffle(all(listi), myrandom);
    loop(i, ans){
        cout << listi[2*i] << " " << listi[(2*i+1)%leaves] << endl;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
