/**
 * Author: MatijaL
 * Time: 2021-05-27 16:44:05
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


mt19937 mt_rand(time(0));
int N, M, K;
char grid[1005][1005];


bool visited[1005][1005];


void dfs(int i, int j){
    if(visited[i][j]) return; 
    visited[i][j] = true;
    if(i > 0 and grid[i-1][j] == '.') dfs(i-1, j);
    if(i < N-1 and grid[i+1][j] == '.') dfs(i+1, j);
    if(j > 0 and grid[i][j-1] == '.') dfs(i, j-1);
    if(j < N-1 and grid[i][j+1] == '.') dfs(i, j+1);
}

int countComponents(){
    memset(visited, 0, sizeof visited);
    ll ans = 0;
    loop(i, N)loop(j, M) if(!visited[i][j] and grid[i][j] == '.'){
        ans++;
        dfs(i, j);
    }
    return ans;
}

void printGrid(){
    loop(i, N){
        loop(j, M){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void solve(){
    cin >> N >> M >> K;
    loop(i, N){
        string s;
        cin >> s;
        loop(j, M){
            grid[i][j] = s[j];
        }
    }

    
    //postavi sadike

    while(1){
        loop(k, K){
            int x, y;
            x = mt_rand()%N;
            y = mt_rand()%M;
            while(grid[x][y] != '.'){
                x = mt_rand()%N;
                y = mt_rand()%M;
            }
            grid[x][y] = 'o';

            if(countComponents() >= 981){
                printGrid();
                return;
            }
            cout << countComponents() << endl;
            loop(i, N){
                loop(j, M){
                    if(grid[i][j] == 'o') grid[i][j] = '.';
                }
            }
        }
    }
    

    

    
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}