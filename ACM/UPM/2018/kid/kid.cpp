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
        if(turn == 1 and check()) return false;//kralj se je nastavil v sah 
        if(turn == 0 and queenAttacked()) return false; //kraljica se nastavlja
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
    vector<State> getValidMoves(){
        vector<State> result;
        if(turn == 0){
            FOR(dx, -1, 1) FOR(dy, -1, 1){
                if(dx == 0 and dy == 0) continue;
                Position newKing = Position(king.x + dx, king.y + dy);
                State newState = State(!turn, newKing, queen);
                if(newState.valid()) result.pb(newState);
            }
        }else{
            FOR(dx, -7, 7) FOR(dy, -7, 7){
                if(dx == 0 and dy == 0) continue;
                if(abs(dx) != abs(dy) and dx != 0 and dy != 0) continue;
                Position newQueen = Position(queen.x + dx, queen.y + dy);
                State newState = State(!turn, king, newQueen);
                if(newState.valid()) result.pb(newState);
            }    
        }
        return result;
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
map<State, int> visited;

int dp(State s){
    if(visited[s] == 2) return memo[s];
    visited[s] = 1;

    int res;
    if(s.turn == 0){

        vector<State> validMoves = s.getValidMoves();
        res = 0;

        //kralj - max
        for(auto nextState : validMoves){
            if(visited[nextState] == 1){
                //gremo upstream
                res = -1;
                break;
            }

            int next = dp(nextState);
            if(next == -1){
                res = -1;
                break;
            }

            res = max(res, next+1);
        }
    }else{
        //kraljica
        vector<State> validMoves = s.getValidMoves();
        vector<int> values;
        for(auto nextState : validMoves){
            if(visited[nextState] == 1)continue;

            int next = dp(nextState);
            if(next == -1) continue;
            values.pb(next);
        }

        if(values.size() == 0) res = -1;
        else{
            res = inf;
            for(auto e : values) res = min(res, e+1);
        }
    }
    //printf("RES KING %d %d || QUEEN %d %d || TURN %d ==> %d\n", s.king.y, s.king.x, s.queen.y, s.queen.x, s.turn, res);
    visited[s] = 2;
    return memo[s] = res;
}

void solve(){
    int ky, kx, qy, qx;
    cin >> ky >> kx >> qy >> qx;
    Position king = Position(kx, ky);
    Position queen = Position(qx, qy);
    State s = State(true, king, queen);
    int res = dp(s);
    if(res == -1) cout << "KRUCIFIKS" << endl;
    else cout << res << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> Y >> X;
    int t;
    cin >> t;
    while(t--) solve();   
}
