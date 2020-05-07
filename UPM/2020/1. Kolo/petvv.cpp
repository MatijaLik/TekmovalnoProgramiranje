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

ll N;
map<pll, char> grid;


bool win(ll x, ll y){
    char ref = grid[mp(x, y)];

    //horzontal
    int h = 0;
    int d = 0;
    while(grid[mp(x+d-4, y)] == ref){
        d++;
        h++;
        if(d == 9)break;
    }
    if(h >= 5) return true;

    //vertical
    int v = 0;
    d = 0;
    while(grid[mp(x, y+d-4)] == ref){
        d++;
        v++;
        if(d == 5)break;
    }
    if(v >= 5) return true;


    //dig1
    int dig1 = 0;
    d = 0;
    while(grid[mp(x+d-4, y+d-4)] == ref){
        d++;
        dig1++;
        if(d == 9)break;
    }
    if(dig1 >= 5) return true;

    //dig2
    int dig2 = 0;
    d = 0;
    while(grid[mp(x+4-d, y+d-4)] == ref){
        d++;
        dig2++;
        if(d == 9)break;
    }
    if(dig2 >= 5) return true;


    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    ll moves_S = 0;
    ll moves_L = 0;

    bool snoopiNaPotezi = true;
    bool victory = false;
    pair<string, ll> winner;

    while(N--){
        ll x, y;
        cin >> x >> y;
        if(victory) continue;

        if(snoopiNaPotezi)moves_S++;
        else moves_L++;


        if(snoopiNaPotezi) grid[mp(x, y)] = 'S';
        else grid[mp(x, y)] = 'L';

        if(win(x, y)){
            victory = true;
            if(snoopiNaPotezi) winner = mp("Snoopy", moves_S);
            else winner = mp("Linus", moves_L);
        }

        snoopiNaPotezi = !snoopiNaPotezi;
    }


    if(!victory) cout << "neodloceno" << endl;
    else cout << winner.first << " " << winner.sc << endl;

}