#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pis pair<int, string>
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

vector <pii> sosedi[110][110];
set<pii> visited;
int w, h;
int smallest = inf;
int largest;
int cnt;
queue<pii> q;

int curSize = 0;

void bfs(){
    while(true){
        if(q.empty()){
            //cout << "new" << endl;
            cnt++;
            largest = max(largest, curSize);
            if(cnt != 1) smallest = min(smallest, curSize);
            curSize = 1;
            bool found = 0;
            loop(i, h) {
                bool b = 0;
                loop(j, w){
                    if(visited.count(mp(i, j))==0){
                        q.push(mp(i, j));
                        visited.insert(mp(i, j));
                        found = 1;
                        b = 1;
                        break;
                    }
                    
                }
                if(b) break;
            }
            if(!found) return;
        }
        pii cur = q.front();
        q.pop();
        //cout << "visiting " << cur.fs << " " << cur.sc << endl;
        for(auto n: sosedi[cur.fs][cur.sc]){
            if(visited.count(n)==0){
                //cout << "adding " << n.fs << " " << n.sc << endl;
                curSize++;
                visited.insert(n);
                q.push(n);
            }
        }
    }
}

int main(){
    cin >> w >> h;
    loop(i, h) loop(j, w){
        int temp;
        cin >> temp;
        if(temp >= 8){
            sosedi[i][j].pb(mp(i, j-1));
            temp -= 8;
        }
        if(temp >= 4){
            sosedi[i][j].pb(mp(i+1, j));
            temp -= 4;
        }
        if(temp >= 2){
            sosedi[i][j].pb(mp(i, j+1));
            temp -= 2;
        }
        if(temp >= 1){
            sosedi[i][j].pb(mp(i-1, j));
            temp -= 1;
        }
    }
    bfs();
    cout << cnt-1 << endl;
    cout << smallest << endl;
    cout << largest << endl;
}