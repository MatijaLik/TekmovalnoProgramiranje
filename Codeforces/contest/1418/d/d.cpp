/**
 * Author: MatijaL
 * Time: 2020-09-19 20:45:01
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

ll sum = 0;
set<int> room;
set<pll> active;
priority_queue<pair<int, pll>> pq;

void add(int x){
    if(room.empty()){
        room.insert(x);
        return;
    }
    auto it = room.upper_bound(x);
    if(it == room.begin()){
        //najvecji do zdaj
        int prev = *(--it);
        cout << "big" << endl;
        pq.push(mp(x-prev, mp(prev, x)));
        active.insert(mp(prev, x));
        sum += x-prev;
    }else if(it == room.rbegin().base() - 1){
        //njamanjsi
        int next = *(it);
        cout << "smol" << endl;
        pq.push(mp(next- x, x, next));
        active.insert(mp(x, next));
        sum += next - x;
    }else{
        
        int prev = *(it-1);
        int next = *(it);
        active.erase(mp(prev, next));
        pq.push(mp(x-prev, mp(prev, x)));
        pq.push(mp(next-x, mp(x, next)));
        active.insert(mp(prev, x));
        active.insert(mp(x, next));

        
        
    }
    room.insert(x);
}
ll ans(){
    if(room.size() <= 2) return 0;

    while(true){
        auto e = pq.top();
        pll interval = e.sc;
        if(active.count(interval)) return sum -  e.fs;
        else pq.pop();
    }
}
void solve(){
    int n, q; 
    cin >> n >> q;
    loop(i,  n){
        int temp;
        cin >> temp;
        add(temp);
    }
    cout << ans() << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
