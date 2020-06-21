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
#define debug(x) cout << "# " << x << endl;


#define nlimit 60

ll grid[nlimit][nlimit];
ll len[nlimit][nlimit];
ll N, P;
ll start_v, start_s;

bool isInside(ll v, ll s){
    if(v < 1 or v > N) return false;
    if(s < 1 or s > N) return false;
    return true;
}


void BFS(ll s_v, ll s_s){
    queue<pll> q;
    q.push(mp(s_v, s_s));
    while(!q.empty()){
        
        pll p = q.front();
        q.pop();

        //printf("BFS %d %d at len %d\n", p.fs, p.sc,len[p.fs][p.sc] );

        ll dv[] = {-2, -2, -1, 1, 2, 2, 1, -1};
        ll ds[] = {-1, 1, 2, 2, 1, -1, -2, -2};
        loop(i, 8){
            if(!isInside(p.fs + dv[i], p.sc + ds[i])) continue;
            if(len[p.fs + dv[i]][p.sc + ds[i]] == -1 and grid[p.fs + dv[i]][p.sc + ds[i]] == '.'){
                len[p.fs + dv[i]][p.sc + ds[i]] = len[p.fs][p.sc]+1;
                q.push(mp(p.fs + dv[i], p.sc + ds[i]));
            } 
        }
    }
}

int main(){
    cin >> N;
    FOR(i,1, N)FOR(j,1, N)len[i][j] = -1;
    FOR(i,1, N){
        string s;
        cin >> s;
        FOR(j,1, N){
            char c =s[j-1];
            grid[i][j] = c;
            if(c == '*'){
                //printf("found at %d %d\n", i, j);
                start_v = i;
                start_s = j;
                len[i][j] = 0;
            }
        }
    }

    

    BFS(start_v, start_s);
    cin >> P;
    loop(i,P){
        ll a, b;
        cin >> a >> b;
        cout << len[a][b] << endl;
    }

}