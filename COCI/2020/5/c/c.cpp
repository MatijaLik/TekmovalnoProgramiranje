/**
 * Author: MatijaL
 * Time: 2021-02-13 16:08:23
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
#define limit 100500
map<pll, int> color;
int n;
int pau, mar;
vector<int> sosedi[limit];

int paudist[limit];
int mardist[limit];

int runCol;

map<int, bool> safe;
bool dfs(int cur, int prev){

    bool good = false;
    
 //  printf("dfs %lld\n", cur);
    for(auto sos : sosedi[cur]){
        if(sos == prev) continue;
        if(color[mp(cur, sos)] == runCol){
            if(safe[cur]){
             //   printf("endpoint %d\n", sos);
             //   printf("safe %d\n", cur);
                return true;
            }
            safe[sos] = true;
            good = good or dfs(sos, cur);
        }else if(color[mp(cur, sos)] == 0){
            if(safe[cur]){
            //    printf("endpoint %d\n", sos);
             //   printf("safe %d\n", cur);
                return true;
            }
            good = good or dfs(sos, cur);
        }
    }
  //  if(good)printf("safe %d\n", cur);
    return good;
}

int memo[200][200][3];
int dp(int paula, int marin, int turn){

    if(memo[paula][marin][turn] != -1) return memo[paula][marin][turn];
    int outcome = -1;
    memo[paula][marin][turn] = 0;

    if(turn == 1){
        //paula na potezi
        outcome = 2;
        for(auto sos : sosedi[paula]){
            if(sos == marin) continue;
            int c = color[mp(paula, sos)];
            if(c == 0 or c == 1){
                int pos = dp(sos, marin, 2);
                if(pos == 0 and outcome == 2) outcome = 0; 
                if(pos == 1) outcome = 1;
            }
        }
    }else{
        outcome = 1;
        for(auto sos : sosedi[marin]){
            if(sos == paula) continue;
            int c = color[mp(marin, sos)];
            if(c == 0 or c == 2){
                int pos = dp(paula, sos, 1);
                if(pos == 0 and outcome == 1) outcome = 0; 
                if(pos == 2) outcome = 2;
            }
        }
    }

    printf("dp %d %d %d --> %d\n", paula, marin, turn, outcome);
    return memo[paula][marin][turn] = outcome;
}

void altSolve(){
    loop(i, 200) loop(j, 200) loop(k, 3) memo[i][j][k] = -1; 
    int ans = dp(pau, mar, 1);
    if(ans == 0) cout << "Magenta" << endl;
    if(ans == 1) cout << "Paula" << endl;
    if(ans == 2) cout << "Marin" << endl;
}

void solve(){
    cin >> n;
    cin >> pau >> mar;
    loop(i, n-1){
        int a, b;
        string c;
        cin >> a >> b >> c;
        sosedi[a].pb(b);
        sosedi[b].pb(a);

        int col;
        if(c == "magenta") col = 0;
        else if(c == "plava") col = 1;
        else if(c == "crvena") col = 2;
        else assert(false);

        color[mp(a, b)] = col;
        color[mp(b, a)] = col;
    }
    /*
    if(n <= 200){
        altSolve();
        return;
    }*/

    //pot paula -> marin
    FOR(i, 1, n) paudist[i] = inf;
    paudist[pau] = 0;

    FOR(i, 1, n) mardist[i] = inf;
    mardist[mar] = 0;

    queue<pll> q;
    q.push(mp(pau, 1));
    q.push(mp(mar, 2));

    pll col = mp(-1LL, -1LL);
    
    bool paumob = false;
    bool marmob = false;
    
    while(!q.empty()){
        pll e = q.front();
        q.pop();

        int node = e.fs;
        int c = e.sc;
       // printf("exploring %lld %lld\n", node, c);

        for(auto sos : sosedi[node]){
            if(c == 1 and mardist[sos] != inf) col = mp(node, sos);
            if(c == 2 and paudist[sos] != inf) col = mp(sos, node);
            if(color[mp(node, sos)] != c and color[mp(node, sos)] != 0) continue; 
            
            if(paudist[sos] != inf or mardist[sos] != inf) continue;
            

          //  printf("found %d\n", sos);
            if(c == 1) {
                paudist[sos] = paudist[node] + 1;
                paumob = 1;
            }
            if(c == 2){
                mardist[sos] = mardist[node] + 1;
                marmob = 1;
            }
            

            
            q.push(mp(sos, c));
        }

        if(col != mp(-1LL, -1LL)) break;
    }
    
    if(col == mp(-1LL, -1LL)){
       // printf("No collision\n");
        if(!paumob) cout << "Marin" << endl;
        else if(!marmob) cout << "Paula" << endl;
        else cout << "Magenta" << endl;
        return;
    }

// printf("Collision is on %lld %lld\n", col.fs, col.sc);

    int turn;
    //1 ce je paula
    //2 ce je marin
    if(paudist[col.fs] == mardist[col.sc]) turn = 1;
    else turn = 2;

// printf("turn %lld\n", turn);
    runCol = turn;

    //MOBILITY TEST
    bool pm = false;
    bool mm = false;

    for(auto sos : sosedi[col.fs]){
        //paulini sosedi
        if(color[mp(col.fs, sos)] != 2){
            if(sos != col.sc or turn == 2){
                pm = true;
            }
        }
    }
    for(auto sos : sosedi[col.sc]){
        //marinovi sosedi
        if(color[mp(col.sc, sos)] != 1){
            if(sos != col.sc or turn == 1){
                mm = true;
            }
        }
    }

  //  if(not(pm and mm)) printf("Immoblity\n");

    if(turn == 1){
        if(!pm){
            cout << "Marin" << endl;
            return;
        }else if(!mm){
            cout << "Paula" << endl;
            return;
        }
    }

    if(turn == 2){
        if(!mm){
            cout << "Paula" << endl;
            return;
        }
        if(!pm){
            cout << "Marin" << endl;
            return;
        }
    }


    bool ans;
    if(turn == 1){
        if(color[mp(col.fs, col.sc)] == 1) safe[col.fs] = true;
        ans = dfs(col.fs, col.sc);
    }
    else{
        if(color[mp(col.fs, col.sc)] == 2) safe[col.sc] = true;
        ans = dfs(col.sc, col.fs);
    }
   
    if(ans) cout << "Magenta" << endl;
    else{
        if(turn == 1) cout << "Marin" << endl;
        else cout << "Paula" << endl;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
