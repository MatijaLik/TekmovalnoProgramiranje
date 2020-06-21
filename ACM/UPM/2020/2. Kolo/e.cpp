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
#define DEBUG false
#if DEBUG
    #define debug(x) cout<< #x << " " << x << endl;
    #define debugIt(x) cout << #x <<": "; for(auto e : x) cout<<x<<", "; cout<<endl;
#else
    #define debug(x) ;
    #define debugIt(x) ;
#endif
 
const double EPS = 0;
 
//map<pair<bool, string>, pair<pair<double, double>, int > > cheat;
 
/*
b = true
| | |
| | |
| | |
b = false
______
______
______
*/
 
bool isStable(double x, double y, vector<vector<int> > g){
    FOR(i,0,3){
        FOR(j,0,3){
            if(i-EPS < x && x < i+1+EPS){
                if(j-EPS < y && y < j+1+EPS){
                    if(i == 1 or j == 1) continue;
                    if(g[i][j] == 0) return false;
                }
            }
        }
    }
    if((1-EPS < x && x < 2+EPS) or (1-EPS < y && y < 2+EPS)){
            if(!(g[0][1] == 1 && g[2][1] == 1)){
                if(!(g[1][0] == 1 && g[1][2] == 1)){
                    return false;
                }
            }
    }
    return true;
}
 
int main(){
    // cheat[mp(0,"111")] = mp(mp(0,0),3);
    // cheat[mp(0,"011")] = mp(mp(0,0),2);
    // cheat[mp(0,"001")] = mp(mp(0,0),1);
    // cheat[mp(0,"110")] = mp(mp(0,0);
    // cheat[mp(0,"100")] = mp(0,0);
    // cheat[mp(0,"101")] = mp(0,0);
    // cheat[mp(0,"010")] = mp(0,0);
    int T;
    cin>>T;
    while(T--){
        bool stable = true;
        int grid[30][3][3];
        FOR(i,0,30) FOR(j,0,3) FOR(v,0,3) grid[i][j][v] = 0;
        int H;
        cin>>H;
        bool b = true;
        vector<string> input;
        string level;
        FOR(i,0,H){
            cin>>level;
            input.pb(level);
            if(b){
                if(level[0] == '1') grid[i][0][0] = grid[i][0][1] = grid[i][0][2] = 1;
                if(level[1] == '1') grid[i][1][0] = grid[i][1][1] = grid[i][1][2] = 1;
                if(level[2] == '1') grid[i][2][0] = grid[i][2][1] = grid[i][2][2] = 1;
            }else{
                if(level[0] == '1') grid[i][0][0] = grid[i][1][0] = grid[i][2][0] = 1;
                if(level[1] == '1') grid[i][0][1] = grid[i][1][1] = grid[i][2][1] = 1;
                if(level[2] == '1') grid[i][0][2] = grid[i][1][2] = grid[i][2][2] = 1;
            }
            b = !b;
        }
 
 
        int grid2[3][3];
        vector<string> answer;
        answer.pb(input[0]);
        FOR(i,1,H){
            FOR(v,0,3)FOR(j,0,3) grid2[v][j] = 0;
            int sumOfAll = 0;
            FOR(j,0,i){
                FOR(x,0,3) FOR(y,0,3){
                    grid2[x][y] += grid[j][x][y];
                    sumOfAll += grid[j][x][y];
                }
            }
            double xBalance = 0;
            FOR(y,0,3)xBalance += 0.5 * grid2[0][y] + 1.5 * grid2[1][y] + 2.5 * grid2[2][y]; 
            xBalance /= sumOfAll;
            double yBalance = 0;
            FOR(x,0,3)yBalance += 0.5 * grid2[x][0] + 1.5 * grid2[x][1] + 2.5 * grid2[x][2]; 
            yBalance /= sumOfAll;
 
            auto getVec = [=](int g[3][3]){
                    vector<vector<int> > vc;
                    FOR(x,0,3){
                        vector<int> v;
                        FOR(y,0,3) v.pb(g[x][y]);
                        vc.pb(v);
                    }
                    return vc;
                };
 
            auto vec = getVec(grid[i]);
 
            if(!isStable(xBalance,yBalance,vec)){
                stable = false;
                break;
            }else{
                string a;
                if(i % 2){
                    FOR(y,0,3){
                        if(grid[i][0][y] == 1){
                            grid[i][0][y] = grid[i][1][y] = grid[i][2][y] = 0;
                            auto vec2 = getVec(grid[i]);
                            grid[i][0][y] = grid[i][1][y] = grid[i][2][y] = 1;
                            if(isStable(xBalance,yBalance,vec2)) a += '*';
                            else a += '1';
                        }else a += '0';
                    }
                }else{
                    FOR(x,0,3){
                        if(grid[i][x][0] == 1){
                            grid[i][x][0] = grid[i][x][1] = grid[i][x][2] = 0;
                            auto vec2 = getVec(grid[i]);
                            #if DEBUG
                                FOR(x,0,3){
                                    FOR(y,0,3) cout<<grid[i][x][y]<<" ";
                                    cout<<endl;
                                }
                                debug(xBalance);
                                debug(yBalance);
                                cout<<endl;
                                FOR(x,0,3){
                                    FOR(y,0,3) cout<<vec2[x][y]<<" ";
                                    cout<<endl;
                                }
                                cout<<endl<<endl;
                            #endif
                            grid[i][x][0] = grid[i][x][1] = grid[i][x][2] = 1;
                            if(isStable(xBalance,yBalance,vec2)) a += '*';
                            else a += '1';
                        }else a+= '0';
                    }
                }
                answer.pb(a);
            }
        }
        if(stable) {
            cout<<"Stabilen :)"<<endl;
            for(auto st : answer) cout<<st<<endl;
        }else cout<<"Nestabilen :("<<endl;
        if(T) cout<<endl;
 
#if DEBUG
        FOR(i,0,H){
            FOR(x,0,3){
                FOR(y,0,3) cout<<grid[i][x][y]<<" ";
                cout<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
#endif
    }
}