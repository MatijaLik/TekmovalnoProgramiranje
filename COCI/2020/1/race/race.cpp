/**
 * Author: MatijaL
 * Time: 2020-10-17 17:18:09
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

    int H, W;
    char grid[105][105];
set<pll> visited;
int dfs(pll node, int depth){
         pll p = node;

        if(p.fs < 0 or p.fs >= H or p.sc < 0 or p.sc >= W) return inf;

        char c = grid[p.fs][p.sc];
        bool b = c == 'o';
        if(b and depth != 0) return inf;
        int best = inf;

        char bestC;
        if(c == '.') return inf;
        if(c == '>' or b){
            pll np = mp(p.fs, p.sc+1);
            int res = dfs(np, depth+1);   
            if(res < best) bestC = 'E';
            best = min(best, res);
        }
     
        if(c == '^' or b){
            pll np = mp(p.fs-1, p.sc);
            int res = dfs(np, depth+1);   
            if(res < best) bestC = 'N';
            best = min(best, res);
        }
        if(c == 'v' or b){
            pll np = mp(p.fs+1, p.sc);
            int res = dfs(np, depth+1);   
            if(res < best) bestC = 'S';
            best = min(best, res);
        }   if(c == '<' or b){
            pll np = mp(p.fs, p.sc-1);
            int res = dfs(np, depth+1);   
            if(res < best) bestC = 'W';
            best = min(best, res);
        }
        if(c == 'x'){
            return 0;
        }
        if(b){
            if(best >= inf){
                cout << ":(" << endl;
            }
            else{
                cout << ":)" << endl;
                cout << bestC << endl;
            }
        }
        return best+1;

}


void solve(){
     
    cin >> H >> W; 
    pll start;

    loop(i, H){
        string s;
        cin >> s;
        loop(j, W){
            if(s[j] == 'o') start = mp(i, j);
            grid[i][j] = s[j];
        }
    
    }

    dfs(start, 0); 

    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
