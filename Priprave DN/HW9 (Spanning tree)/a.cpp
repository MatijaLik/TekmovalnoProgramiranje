#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <set>
#include <stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
#define mii map<int, int>
#define si set<int>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf ll_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


int main(){
    ll N;
    cin >> N;
    vector<ll> sosedi[N+3];
    loop(i, N-1){
        ll a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
    bool color[N+3];
    loop(i, N+3) color[i] = false;
    color[1] = false;
    ll count[2] = {1,0};
    set<ll> visited;
    visited.insert(1);
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll a = q.front();
        q.pop();
        for(ll sosed : sosedi[a]){
            if(visited.count(sosed)==0){
                visited.insert(sosed);
                q.push(sosed);
                color[sosed] = !color[a];
                if(color[sosed]) count[1]++;
                else count[0]++;
            }
        }
    }
    cout << (count[0]*count[1]) - N + 1 << endl;
    return 0;

}