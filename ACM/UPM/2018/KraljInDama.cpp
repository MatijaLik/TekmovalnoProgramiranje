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
 
 
ll memo[10][10][10][10][2];
ll V, S;
 
 
bool check(ll king_y, ll king_x, ll queen_y, ll queen_x){//ali je kralj v sahu
    if(king_y == queen_y) return true;
    if(king_x == queen_x) return true;
    if(king_x - king_y == queen_x - queen_y) return true;
    if(king_x + king_y == queen_x + queen_y) return true;
    return false;
}
 
bool queenAttacked(ll king_y, ll king_x, ll queen_y, ll queen_x){//ali lahko kralj poje kraljico
    if(abs(king_y - queen_y) <= 1 and abs(king_x - queen_x) <= 1) return true;
    return false;
}
 
bool isInside(ll x, ll y){// ali je figura na sahovnici
    if(y < 1 or y > V or x < 1 or x > S)return false;
    return true;
}
 
 
ll dp(ll king_y, ll king_x, ll queen_y, ll queen_x, ll turn){
    //izven sahovnice
    //if(!isInside(king_x, king_y)) return inf;
    //if(!isInside(queen_x, queen_y)) return inf;
    
    if(memo[king_y][king_x][queen_y][queen_x][turn] != -1) return memo[king_y][king_x][queen_y][queen_x][turn];
    memo[king_y][king_x][queen_y][queen_x][turn] = inf; //zacasno
 
    //printf("DP KING %d %d || QUEEN %d %d || TURN %d\n", king_y, king_x, queen_y, queen_x, turn);
    ll res;
    if(turn){//kralj na potezi
        res = 0;
        ll good = 0;//ali je sploh moyno kaj nareit
        ll dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        ll dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
        loop(i, 8){
            if(!check(king_y+dy[i], king_x+dx[i], queen_y, queen_x) and isInside(king_x+dx[i], king_y+dy[i])){
                good = 1;
                res = max(res, 1+dp(king_y+dy[i], king_x+dx[i], queen_y, queen_x, 0));
            }
        }
        if(!good) res = 0;//smo zakljucili
    }else{//dama na potezi
        res = inf;
        FOR(dx, -7, 7){
            FOR(dy, -7, 7){
                if(dx == 0 and dy == 0) continue;//stoji na mestu
                if(abs(dy) != abs(dx) and dx!=0 and dy!=0) continue;//ni legalen premik
                if(!queenAttacked(king_y, king_x, queen_y+dy, queen_x + dx) and isInside(queen_x+dx, queen_y+dy)){
                    res = min(res, 1+dp(king_y, king_x, queen_y+dy, queen_x + dx, 1));
                }
            }
        }
    }
    //printf("RES KING %d %d || QUEEN %d %d || TURN %d ==> %d\n", king_y, king_x, queen_y, queen_x, turn, mini);
    return memo[king_y][king_x][queen_y][queen_x][turn] = res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    loop(i, 10)loop(j, 10)loop(k, 10)loop(l, 10) loop(m , 2) memo[i][j][k][l][m] = -1;
    cin >> V >> S;
    ll P;
    cin >> P;
    while(P--){
        ll yk, xk, yd, xd;
        cin >> yk >> xk >> yd  >> xd;
        ll ans = dp(yk, xk, yd, xd, 0);
 
        if(ans < 1000000) cout << ans << endl;
        else cout << "KRUCIFIKS" << endl;
    } 
}