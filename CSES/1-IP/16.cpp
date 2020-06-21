#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl

const int side = 7;

ll cnt = 0;
vector<string> paths;
bool visited[10][10];

string s;

//#include <chrono>


void dfs(int x, int y, int len){
    //cout << path << " | " << x << " " << y <<endl;

    visited[x][y] = true;

    if(x == 0 and y == side-1 and len + 1 == side*side){
        cnt++;
    }


    if((x == 0 and y == side-1) or len + 1 == side*side){
        visited[x][y] = false;
        return;
    }

    //zajebal se je, ce
    // 1. je spredaj visted, L in R pa oba unvisited

    bool u = y-1 < 0 or visited[x][y-1]; 

    bool d = y+1 >= side or visited[x][y+1];

    bool l = x-1 < 0 or visited[x-1][y];

    bool r = x+1 >= side or visited[x+1][y];

    
    if(u and d and !l and !r){visited[x][y] = false; return;}
    if(l and r and !u and !d){visited[x][y] = false; return;}


    //ciganska optimizacija
    char c = s[len];

    if(!d and (c == '?' or c == 'D')) dfs(x, y+1, len + 1);
    if(!l and (c == '?' or c == 'L')) dfs(x-1, y, len + 1);
    if(!r and (c == '?' or c == 'R')) dfs(x+1, y, len + 1);
    if(!u and (c == '?' or c == 'U')) dfs(x, y-1, len + 1);
    

    visited[x][y] = false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s;

    //auto t1 = chrono::high_resolution_clock::now();
    dfs(0, 0, 0);
    //auto t2 = std::chrono::high_resolution_clock::now();



    cout << cnt << endl;


    //auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    //cout << duration/1000 << endl;
}