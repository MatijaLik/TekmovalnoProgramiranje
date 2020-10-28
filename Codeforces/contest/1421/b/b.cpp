/**
 * Author: MatijaL
 * Time: 2020-10-18 13:06:57
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
int N;
const int limit = 210;
bool visited[limit][limit];
int grid[limit][limit];
void dfs(int x, int y){
    if(x < 1 or x > N or y < 1 or y > N) return;
    visited[x][y] = true;
    int c  = grid[x][y];
    vector<int> dx = {1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1};

    loop(i, 4){
        int d1 = dx[i];
        int d2 = dy[i];
        if(grid[x+d1][y+d2] == c) dfs(x+d1, y + d2);
    }
}
void solve(){
    cin >> N;
    memset(visited, 0, sizeof visited);
    memset(grid, 0, sizeof grid);
    
    grid[1][1] = 2;
    grid[N][N] = 2;
    FOR(i, 1, N){
        string s;
        cin >> s;
        FOR(j, 1, N){
            char c = s[j-1];
            int a = c-'0';
            grid[i][j] = a;
        }
    }
    
    int a = grid[1][2];
    int b = grid[2][1];
    int c = grid[N][N-1];
    int d = grid[N-1][N];
    if(a == b){
        int i = 0;
        if(c == a) i++;
        if(d == a) i++;
        cout << i << endl;

        if(c == a) cout << N << " " << N-1 << endl;
        if(d == a) cout << N-1 << " " << N << endl;
    }
    else if(c == d){
        int i = 0;
        if(a == c) i++;
        if(b == c) i++;
        cout << i << endl;

        if(a == c) cout << 1 << " " << 2 << endl;
        if(b == c) cout << 2 << " " << 1 << endl;
    }else{
        cout << 2 << endl;
        if(a == d){
            cout << 1 << " " << 2 << endl;
            cout << N << " " << N-1 << endl;
        }else{
            cout << 1 << " " << 2  << endl;
            cout << N-1 << " " << N<< endl;
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
