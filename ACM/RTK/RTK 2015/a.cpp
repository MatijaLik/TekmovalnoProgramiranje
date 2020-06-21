#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <initializer_list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 2000

char grid[limit][limit];
bool visited[limit][limit];
int W, H;

int bDFS(int i, int j){
    //printf("dfs %d %d\n", i, j);
    if(i >= H or j >= W or i < 0 or j < 0) return 0;
    if(visited[i][j]) return 0;
    if(grid[i][j]!='#') return 0;
    visited[i][j] = 1;
    return bDFS(i+1,j) + bDFS(i-1,j) + bDFS(i,j+1) + bDFS(i,j-1) + 1;
}
pii wDFS(int i, int j){
    //printf("dfs %d %d\n", i, j);
    if(i >= H or j >= W or i < 0 or j < 0) return mp(0,0);
    if(visited[i][j]) return mp(0,0);
    if(grid[i][j]=='#') return mp(0,0);
    visited[i][j] = 1;
    char c = grid[i][j];
    int num = -10;
    if((int) c > 47 and (int) c < 58){num = (int)c - '0';}
    pii p1 = wDFS(i+1,j);
    pii p2 = wDFS(i-1,j);
    pii p3 = wDFS(i,j+1);
    pii p4 = wDFS(i,j-1);
    int mx = max(max(p1.fs, p2.fs), max(p3.fs, p4.fs));
    int out = max(mx, num);
    if(mx > 0 and num > 0) out = -1;
    return mp(out, p1.sc+p2.sc+p3.sc+p4.sc+1);
}

int main(){
    cin >> W >> H;
    loop(i, H)loop(j, W) cin >> grid[i][j];

    int bcnt = 0;
    loop(i, H)loop(j, W){
        if(bDFS(i, j)) bcnt++;
    }
    cout << bcnt << endl;

    int wcnt = 0;
    int wccnt = 0;
    loop(i, H)loop(j, W){
        pii p = wDFS(i, j);
        if(p.sc){
            wcnt++;
            if(p.sc==p.fs) wccnt++;
            //cout << p.sc << " " << p.fs << endl;
        }
    }
    cout << wcnt << endl;
    cout << wccnt << endl;

    int lcnt = 0;
    for(int i = 0; i < H-1; i++){
        for(int j = 0; j < W-1; j++){
            if(
                grid[i][j]=='#' and
                grid[i+1][j]=='#' and
                grid[i][j+1]=='#' and
                grid[i+1][j+1]=='#'
            ) lcnt++;
        }
    }
    cout << lcnt << endl;
}