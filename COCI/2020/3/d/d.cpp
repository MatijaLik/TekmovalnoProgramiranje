/**
 * Author: MatijaL
 * Time: 2020-12-12 16:33:01
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

#define limit 10500

ll r[limit];
ll parent[limit];

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void un(ll x, ll y){
    //printf("un %lld %lld\n", x, y);
    ll xRoot = find(x);
    ll yRoot = find(y);
    if(xRoot == yRoot) return;
    if(r[xRoot]<r[yRoot]){
        ll temp = yRoot;
        yRoot = xRoot;
        xRoot = temp;
    }
    parent[yRoot] = xRoot;
    if(r[xRoot] == r[yRoot]) r[xRoot]++;
}

int h(int i, int j){
    return i*10 + j;
}

void solve(){
    loop(i, limit) parent[i] = i;
    int N, M;
    cin >> N >> M;

    bool grid[N][M];
    memset(grid, 0 , sizeof grid);


    loop(i, N){
        string s;
        cin >> s;
        int j =0;
        for(auto c : s){
            
            if(c == '#') {
                grid[i][j] = true;
                //printf("%d\n", h(i, j));
            }j++;
        }
    }

    loop(i, N)loop(j, M){
        if(grid[i][j] == false) continue;

        //gor
        if(i != 0 and grid[i-1][j]) un(h(i, j), h(i-1, j));

        //desno
        if(j != M-1 and grid[i][j+1]) un(h(i, j), h(i, j+1));
    }

    set<int> comp;
    loop(i, N)loop(j, M){
        if(grid[i][j]) comp.insert(find(h(i, j)));
    }

    cout << comp.size() << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
