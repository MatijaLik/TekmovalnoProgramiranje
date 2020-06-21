#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <string.h>
#include <math.h> 
 
using namespace std;
typedef long long LL;
typedef long double LD;
 
#define inf 999999999999;
#define FOR(i,n,m) for(LL i = n; i < m; i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (x).size()
#define all(v) (v).begin(),(v).end()
template<typename T> void PV(T v) {
	for(const auto e : v) cout<<e<<" "; cout<<endl;
}

map<pair<LL,LL>, int> grid;

bool win(LL x, LL y){
    int grid2[9][9];
    FOR(i,0,9)FOR(j,0,9){
        if(grid.find(mp(x-4+i,y-4+j)) == grid.end()) grid2[i][j] = 0;
        else grid2[i][j] = grid[mp(x-4+i,y-4+j)];
    }
    
    int hor = -1, ver = -1, dig1 = -1, dig2 = -1;

    //HORIZONTAL
    LL i = 4, j = 4; 
    while(grid2[i][j] == grid2[4][4]){
        i--;
        hor++;
        if(i == -1) break;
    }
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        i++;
        hor++;
        if(i == 9) break;
    }

    //VERTICAL
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        j--;
        ver++;
        if(j == -1) break;
    }
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        j++;
        ver++;
        if(j == 9) break;
    }

    //DIG1
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        i--;
        j--;
        dig1++;
        if(i == -1) break;
    }
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        i++;
        j++;
        dig1++;
        if(i == 9) break;
    }

    //DIG2
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        j--;
        i++;
        dig2++;
        if(j == -1) break;
    }
    i = 4, j = 4;
    while(grid2[i][j] == grid2[4][4]){
        j++;
        i--;
        dig2++;
        if(j == 9) break;
    }

    if(ver >= 5) return true;
    if(hor >= 5) return true;
    if(dig1 >= 5) return true;
    if(dig2 >= 5) return true;
    return false;
}

int main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<string, int> winner;
    bool over = false;
    int n;
    cin>>n;
    int m = n;
    bool p = true;  
    //true = snoopy
    
    int s = 0, l = 0;
    while(n--){
        LL x, y;
        cin>>x>>y;
        grid[mp(x,y)] = (p ? 1 : 2);
        if(win(x,y) && over == false){
            winner = mp((p ? "Snoopy" : "Linus"),(p ? s+1 : l+1));
            over = true;
        }
        if(p) s++;
        else l++;
        p = !p;
    }

    if(over == false){
        cout<<"neodloceno"<<endl;
    }else{
        cout<<winner.fs<<" "<<winner.sc<<endl;
    }
    return 0; 
}