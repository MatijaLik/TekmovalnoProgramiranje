#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
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
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

ll V, S;
ll grid[510][510];
ll ps[510][510];
ll mag;
ll linglingCnt;


void prllPS(){
    cout << "#####" << endl;
    loop(i, V) {
        loop(j, S){
            cout << ps[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "#####" << endl;
    return;
}

ll erect(ll x, ll y, ll a, ll b){
    ll cnt = 0;
    cnt += ps[y+b-1][x+a-1]; //spodaj levo

    if(y != 0) cnt -= ps[y-1][x+a-1];
    if(x != 0) cnt -= ps[y+b-1][x-1];

    if(x != 0 and y != 0) cnt += ps[y-1][x-1];
    return cnt;
}


int main(){
    cin >> V >> S;
    loop(i, V) loop(j, S){
        char c;
        cin >> c;
        if(c == '.'){
            grid[i][j] = 0;
        }else{
            linglingCnt++;
            grid[i][j] = 1;
        }
        ps[i][j] += grid[i][j];
        //dol in desno
        if(i+1 < V) ps[i+1][j] += ps[i][j];
        if(j+1 < S) ps[i][j+1] += ps[i][j];
        //diagonala
        if(i+1< V and j+1 < S) ps[i+1][j+1] -= ps[i][j];
    }

    //prllPS();
    for(ll a = 1; a <= linglingCnt; a++){
        if(linglingCnt%a>0) continue;
        ll b = linglingCnt / a;
        
        for(ll x = 0; x <= S-a; x++){
            for(ll y = 0; y <= S-b; y++){
                mag = max(mag, erect(x, y, a, b));
            }
        }
    }
    cout << linglingCnt - mag << endl;




}

