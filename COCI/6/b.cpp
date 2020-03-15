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
#define limit 100010
ll N, M, Q, K;
ll cBFS, nBFS;
queue<ll> q;
double dis[limit];
ll visited[limit];
vector <ll> sosedi[limit];

void BFS(){
    int nBFS = Q;
    int cnt = 0;
    int day = 1;
    int X = 1;
    while(!q.empty()){
        loop(p, K*X){
            cnt=0;
            int temp = nBFS;
            while(cnt < temp and !q.empty()){
                int node = q.front();
                q.pop();
                nBFS--;
                cnt++;
                for(auto sosed : sosedi[node]){
                    if(visited[sosed]==0){
                        //cout << "day " << day << " vsisted " << sosed << endl;
                        nBFS++;
                        q.push(sosed);
                        visited[sosed] = 1;
                        dis[sosed]=day;
                    }
                }
            }
        }
        //cout << "day ended " << nBFS << endl; 
        if(nBFS == 0) return;
        X++;
        day++;
    }
    
}


int main(){
    cin >> N >> M >> Q >> K;
    cBFS = Q;
    loop(i, Q){
        ll insider;
        cin >> insider;
        q.push(insider);
        dis[insider] = 0;
        visited[insider] = 1;
    }
    loop(i, M){
        ll a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    BFS();
    loop(i , N) cout << dis[i+1] << " ";
    cout << endl;
}