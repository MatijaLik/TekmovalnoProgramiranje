/**
 * Author: MatijaL
 * Time: 2020-11-07 17:18:45
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
struct Node{
    int x, y;
    int t, d;
    Node(int _x, int _y, int _t, int _d){
        x = _x;
        y = _y;
        t = _t;
        d = _d;
    }
    bool compatible(Node other){
        int time = abs(other.t - t);
        int dist = abs(x - other.x) + abs(y - other.y);
        if(time >= dist) return true;
        else return false;
    }

};

void solve(){
    int R, N;
    cin >> R >> N;
    
    Node top = Node(1, 1, 0, 0);
    vector<Node> v;
    int best = 0;
    v.pb(top);
    loop(i, N){
        int x, y, t;
        cin >> t >> x >> y;
        Node sug = Node(x, y, t, 0);
        for(int i = 0; i < v.size() and i <= 4*R; i++){
            Node pos = v[v.size()-1-i];
            if(sug.compatible(pos)){
                sug.d = max(sug.d, pos.d+1);
            }
        }
        if(sug.d != 0) v.pb(sug);
        best = max(best, sug.d);
    }
    cout << best << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
