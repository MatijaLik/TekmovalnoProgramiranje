#include <iostream>
#include <set>
#include <vector>
#include <queue>
typedef long long ll;
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define limit 1e9
set <pii> allowed;
set <pii> visited;
ll x0, y0, x1, y1;
ll length = 1e6;
queue <pair<pii, int>> flood;
void floodfill(){
    while (true){
	if(flood.empty()) return;
	pair<pii, int> p = flood.front();
	flood.pop();
	ll x = p.first.first;
	ll y = p.first.second;
	ll len = p.second;
    
    ll dx[8] = {
	-1,-1,0,1,1,1,0,-1
    };
    ll dy[8] = {
	0,1,1,1,0,-1,-1,-1
    };
    if(x==x1 && y == y1){
	length = min(length, len);
	return;
    }
    for(int i = 0; i < 8; i++){
	if(x+dx[i]<=0 || x+dx[i] > limit || y + dy[i]<= 0 || y + dy[i] > limit) continue;
	pii next = make_pair(x+dx[i], y+dy[i]);
	if(allowed.count(next)> 0 && visited.count(next)==0){
	    flood.push(mp(mp(x+dx[i], y +dy[i]), len+1));
		    //cout << x+dx[i] << " " << y + dy[i] << endl;
	    visited.insert(make_pair(x+dx[i],y+dy[i]));
    
	}
    }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x0 >> y0 >> x1 >> y1;
    ll n;
    cin >> n;
    for(int i = 0; i<n;i++){
	ll r, a, b;
	cin >> r >> a >> b;
	for(int c = a; c<=b; c++){
	    allowed.insert(make_pair(r, c));
	}
    }
    visited.insert(mp(x0,y0));
    flood.push(mp(mp(x0, y0), 0));
    floodfill();
    if(length == 1e6) cout << -1 << endl;
    else cout << length << endl;
    return (0);
}
