#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
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

int grid[510][510];
int og[510][510];
int N, M;

int main(){
    cin >> N >> M;
    loop(i, N) loop(j, M){
        char c;
        cin >> c;
        int h = (int)c - '0';
        grid[i][j] = h;
        og[i][j] = h;
    }
    int cnt = 0;
    loop(i, N) loop(j, M){
        if(og[i][j]==1)continue;
        cnt++;
        //2 izbiri
        bool r = og[i][j-1];
        bool d = og[i-1][j];
        //if(r||d) cout << "found at " << i+1 << " " << j+1  << " " << r << d <<endl;
        if(not(r||d)) continue;
        int cr = 0;
        int cd = 0;
        int pivot = 0;
        while(og[i][j+pivot]==0 and j+pivot < M){
            if(grid[i][j+pivot]==0) cr++;
            pivot++;
        }
        pivot = 0;
        while(og[i+pivot][j]==0 and i+pivot < N){
            if(grid[i+pivot][j]==0)cd++;
            pivot++;
        }
        if(r && d){
            if(max(cd, cr)==0)continue;
            if(cd != 1){
                cout << i << " " << j+1 << " DOLJE" << endl;
                loop(h, cd+1) grid[i+h][j] = 1;
            }
            if(cr != 1){
                cout << i+1 << " " << j << " DESNO" << endl;
                loop(h, cr+1) grid[i][j+h] = 1;
            }
            if(cd == cr and cd == 1){
                cout << i+1 << " " << j << " DESNO" << endl;
                loop(h, cr+1) grid[i][j+h] = 1;
                cout << i << " " << j+1 << " DOLJE" << endl;
                loop(h, cd+1) grid[i+h][j] = 1;
            }
            
        }else if(r and cr){
            cout << i << " " << j+1 << " DESNO" << endl;
            int pivot = 0;
            while(og[i][j+pivot]==0 and j+pivot < M){
                grid[i][j+pivot] = 1;
                pivot++;
            }
        }else if(d and cd){
            cout << i+1 << " " << j << " DOLJE" << endl;
            int pivot = 0;
            while(grid[i+pivot][j]==0 and i+pivot < N){
                grid[i+pivot][j] = 1;
                pivot++;
            }
        }
        /*
        loop(i, N){
            loop(j, M){
                cout << grid[i][j];
            }
            cout << endl;
        }*/

    }

}