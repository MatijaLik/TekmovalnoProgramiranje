/**
 * Author: MatijaL
 * Time: 2020-10-03 19:11:10
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


//Dolzina in sirina zadeve
int X, Y;

struct Position{
    int x;
    int y;
    Position(){
        x = 0;
        y = 0;
    }
    Position(int a, int b){
        x = a;
        y = b;
    }
    bool valid(){
        bool b1 = (1 <= x) and (x <= X);
        bool b2 = (1 <= y) and (y <= Y);
        return b1 and b2;
    }
};
bool operator <(Position const &a, Position const &b){
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
bool operator == (Position const &a, Position const &b){
    if(a.x == b.x) return a.y == b.y;
    else return false;
}
struct State{
    bool turn;//0 - king | 1 - queen
    Position king;
    Position queen;   
    State(bool t, Position a, Position b){
        turn = t;
        king = a;
        queen = b;
    }
    bool valid(){
        if(!(king.valid() and queen.valid())) return false;
        return true;
    }

    bool check(){
        if(king.x == queen.x) return true;
        if(king.y == queen.y) return true;
        if(king.x - king.y == queen.x - queen.y) return true;
        if(king.x + king.y == queen.x + queen.y) return true;
        return false;
    }
    bool queenAttacked(){
        if(abs(king.x - queen.x) <= 1 and abs(king.y - queen.y) <= 1) return true;
        return false;
    }
    vector<State> getNextMoves(bool backTrack){
        vector<State> result;
        if(turn == 0){
            FOR(dx, -1, 1) FOR(dy, -1, 1){
                if(dx == 0 and dy == 0) continue;
                Position newKing = Position(king.x + dx, king.y + dy);
                State newState = State(!turn, newKing, queen);
                //if(!newState.valid()) printf("Jao retard1\n");
                //if(check()) printf("Jao retard 2\n");
                if(newState.valid() and (backTrack or !newState.check()) and !newState.queenAttacked()){
                    //printf("ide\n");
                    result.pb(newState);
                }
            }
        }else{
            FOR(dx, -7, 7) FOR(dy, -7, 7){
                if(dx == 0 and dy == 0) continue;
                if(abs(dx) != abs(dy) and dx != 0 and dy != 0) continue;
                Position newQueen = Position(queen.x + dx, queen.y + dy);
                State newState = State(!turn, king, newQueen);
                if(newState.valid() and !newState.queenAttacked()) result.pb(newState);
            }    
        }
        //if(!backTrack)printf("%d\n", result.size());
        return result;
    }

    vector<State> getPrevMoves(){
        State stateConjugate = State(!turn, king, queen);
        vector<State> result = stateConjugate.getNextMoves(true);

        vector<State> finalResult;
        if(turn == 0){
            //na potezi kralj
            ///gledamo mozne poteze kraljice, tako da pred tem ni bil kralj v sahu
            
            for(auto r : result){
                r.turn = !r.turn;
                if(!r.check()) finalResult.pb(r);
            }
        }else{
            //na potezi kraljica
            //prej je bil na potezi kralj
            for(auto r : result){
                r.turn = !r.turn;
                finalResult.pb(r);
            }
        }
        return finalResult;
    }
};
bool operator <(State const &a, State const &b){
    if(a.turn == b.turn){
        if(a.king == b.king) return a.queen<b.queen;
        return a.king < b.king;
    }
    return a.turn < b.turn;
}

map<State, int> memo;

//0 unvisited| 1 upstream | 2 finished
set<State> visited;

queue<pair<State, int>> q;




void getMates(){
    //generiraj vse mate
    vector<Position> kingV = {Position(1, 1), Position(1, Y), Position(X, 1), Position(X, Y)};

    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for(auto king : kingV){
        loop(i, 8){
            Position queen = Position(king.x + dx[i], king.y + dy[i]);
            if(queen.valid()){
                State s = State(0, king, queen);
                q.push(mp(s, 0));
                //printf("MATE || KING %d %d || QUEEN %d %d\n", king.y, king.x, queen.y, queen.x);
            }
        }
    }
}

void bfs(){

    pair<State, int> p = q.front();
    q.pop();
    State s = p.fs;
    int depth = p.sc;
    if(visited.count(s)) return;

    //verification (iff turn == 0)
    if(s.turn == 0 and depth != 0){   
        //printf("VER %d || KING %d %d || QUEEN %d %d || turn %d\n", depth, s.king.y, s.king.x, s.queen.y, s.queen.x, s.turn);
        vector<State> nm = s.getNextMoves(0);
        for(auto ns : nm){
            if(visited.count(ns) == 0) return;
        }
        //printf("Verified! on %d examples\n", nm.size());
    }
    //2 || KING 2 3 || QUEEN 2 1
    //4 || KING 1 3 || QUEEN 3 1
    //4 || KING 1 3 || QUEEN 3 2 || turn 0
    visited.insert(s);
    memo[s] = depth;
    
    
    //printf("%d || KING %d %d || QUEEN %d %d || turn %d\n", depth, s.king.y, s.king.x, s.queen.y, s.queen.x, s.turn);
    //push forward
    for(auto ps : s.getPrevMoves()){
        if(visited.count(ps)) continue;
        q.push(mp(ps, depth+1));

        //printf("GEN %d || KING %d %d || QUEEN %d %d || turn %d\n", depth, ps.king.y, ps.king.x, ps.queen.y, ps.queen.x, ps.turn);
    }

}

void query(State s){
    if(visited.count(s) == 0) printf("KRUCIFIKS\n");
    else printf("%d\n", memo[s]);
}

void solve(){
    int ky, kx, qy, qx;
    cin >> ky >> kx >> qy >> qx;
    Position king = Position(kx, ky);
    Position queen = Position(qx, qy);
    State s = State(true, king, queen);
    query(s);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> Y >> X;
    getMates();
    while(!q.empty()) bfs();
    //printf("Ended precomputation\n");
    int t;
    cin >> t;
    while(t--) solve();   
}
