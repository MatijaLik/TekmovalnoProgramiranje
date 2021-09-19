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

    int flowers = K;
    //postavi sadike
    int rep = 1;
    while(rep--){
        //naredi sahovnica
        FOR(X, 0, 50){
            FOR(Y, 0, 50){
                int x0 = 1+20*X;
                int y0 = 1+20*Y;
                

                int x = x0;
                int y = y0;

                int xm = 0;
                int ym = 0;
                while(flowers>0 and y - y0 <= 18){
                    
                    //sahovnica 863
                    if(
                        (xm+y)%2 == 0 and 
                        grid[y][x0+xm] == '.'
                        
                        
                        and
                        (
                            (
                            (grid[y][x0+xm+1] == '.' or xm == 18)
                            and 
                            (grid[y][x0+xm-1] == '.' or xm==0)
                            )

                            or

                            (
                            (grid[y+1][x0+xm] == '.' or ym == 18)
                            and 
                            (grid[y-1][x0+xm] == '.' or ym==0)
                            )
                        )
                    )
                        {
                        //printf("%lld %lld\n", y, x+xm);
                        grid[y][x+xm] = 'o';
                        flowers--;
                    }

                    /* predalcki 467
                    //printf("%d %d\n", xm, ym);
                    if(( xm % 3 == 2 )!= (ym % 3 == 2)){
                        //printf("bulding\n");
                        if(grid[y][x0+xm] == '.'){
                            flowers--;
                            grid[y][x0+xm] = 'o';
                        }
                    }*/


                    xm++;
                    if(xm == 19){
                        xm = 0;
                        y++;
                        ym++;
                    }
                }
            }
        }
        cout << countComponents() << endl;
        printGrid();
    }
    

    

    
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
