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
int N, M;
bool grid[1010][1500];
ll ans = 0;
bool visited[1010][1500];

/*
0 - gor
1 - dol
2 - levo
3 - desno

*/

pair<int, int> start;

void dfs(int i, int j, int dir){

    bool joze = false;
    if(dir == -1){
        joze = true;
        ans++;
    }
    //printf("%d %d | %d\n", i, j, dir);
    visited[i][j] = true;

    //gor
    if(i != 0 and grid[i-1][j] and !visited[i-1][j]){
        if(!joze and dir != 0) dfs(i-1, j, -1);
        else dfs(i-1, j, 0);
        return;
    }

    //dol
    if(i != N-1 and grid[i+1][j] and !visited[i+1][j]){
        if(!joze and dir != 1) dfs(i+1, j, -1);
        else dfs(i+1, j, 1);
        return;
    }

    //levo
    if(j != 0 and grid[i][j-1] and !visited[i][j-1]){
        if(!joze and dir != 2) dfs(i, j-1, -1);
        else dfs(i, j-1, 2);
        return;
    }

    //desno
    if(j != M-1 and grid[i][j+1] and !visited[i][j+1]){
        if(!joze and dir != 3) dfs(i, j+1, -1);
        else dfs(i, j+1, 3);
        return;
    }

    

}

void predfs(int i, int j, int pi, int pj){
    pair<int, int> bad = mp(pi, pj);


    if(bad == mp(-1, -1) and mp(i, j) == start){
        dfs(i, j, -1);
        return;
    }

    //gor
    if(i != 0 and grid[i-1][j] and !visited[i-1][j]){
        if(mp(i-1, j) != bad){
            predfs(i-1, j, i, j);
            return;
        }
    }

    //dol
    if(i != N-1 and grid[i+1][j] and !visited[i+1][j]){
        if(mp(i+1, j) != bad){
            predfs(i+1, j, i, j);
            return;
        }
    }

    //levo
    if(j != 0 and grid[i][j-1] and !visited[i][j-1]){
        if(mp(i, j-1) != bad){
            predfs(i, j-1, i, j);
            return;
        }
    }

    //desno
    if(j != M-1 and grid[i][j+1] and !visited[i][j+1]){
        if(mp(i, j+1) != bad){
            predfs(i, j+1, i, j);
            return;
        }
    }

    dfs(i, j, -1);
    return;
}



void solve(){
    //cout << 2 << endl;
    



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
        
        if(!visited[i][j] and grid[i][j]){
            //printf("new\n");
            start = mp(i, j);
            predfs(i, j, -1, -1);
        }
        
    }

    cout << ans << endl;



}



mt19937 mt_rand(time(0));

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
