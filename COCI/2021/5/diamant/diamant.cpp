/**
 * Author: MatijaL
 * Time: 2022-03-05 15:11:24
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
ll cnt=0;
const bool DEBUG = 0;
void solve(){
    int n,m;
    cin >> n >> m;
    char grid[n][m];
    memset(grid, 0, sizeof grid);
    loop(i, n){
        string s;
        cin  >> s;
        loop(j, m){
            grid[i][j]=s[j];
        }
    }
    int N = 2*(n+m+5);
    int M = N;
    char a[N][M];
    loop(i, N) loop(j, M) a[i][j]='.';
    loop(i, n){
        loop(j, m){
            a[i-j+m+3][i+j+3] = grid[i][j];
            assert(i-j+m >= 0);
        }
    }

    //print a
    if(DEBUG){
        loop(i, N){
        loop(j, M){
            cout << a[i][j];
        }
        cout << endl;
    }
    }
    
    ll cumsum[N][M];
    loop(i, M) cumsum[0][i]=0;
    loop(i, N) cumsum[i][0]=0;
    FOR(i, 1, N-1){
        FOR(j, 1, M-1){
            cumsum[i][j] = cumsum[i-1][j] + cumsum[i][j-1] - cumsum[i-1][j-1];
            if(a[i][j]=='#') cumsum[i][j]++;
        }
    }

    //original grid
    FOR(x, 0, m-1){
        int prev=-1;
        FOR(y, 0, n-1){
            if(grid[y][x]=='#'){
                if(prev==-1){
                    prev=y;
                }else{
                    //preveri diamant
                    int fi=prev-x+m+3;
                    int fj=prev+x+3;

                    int si=y-x+m+3;
                    int sj=y+x+3;

                    assert(si>0 && sj>0 && fi>0 && fj>0);
                    assert(si<N && fi < N && sj<M && fj<M);

                    if(DEBUG)printf("Diamond line %d [%d %d]\n", x, prev, y);

                    //zunanja
                    ll outer = cumsum[si][sj]
                                - cumsum[si][fj-1]
                                - cumsum[fi-1][sj]
                                + cumsum[fi-1][fj-1];

                    ll inner = cumsum[si-1][sj-1]
                                - cumsum[si-1][fj]
                                - cumsum[fi][sj-1]
                                + cumsum[fi][fj];

                    ll expected = (y-prev)*2;

                    if(DEBUG)printf("%d %d\n", outer, inner);
                    if((outer==expected) and (outer != 2)and (inner==0)){
                        cnt++;
                        if(DEBUG)printf("OK\n");
                    }
                    prev=y;
                }
            }
        }
    }
    cout << cnt << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
