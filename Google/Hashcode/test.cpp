#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pli pair<long long, int>
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
#define inf 999999999
#define mod 1000000007
int N, M, K;

int main(){
    int res = 0;
    cin >> N >> M >> K;
    map <pii, ll> w;
    vector <int> n[100010];
    loop(i, M){
		int a, b;
		int x;
		cin >> a >> b >> x;
		int mn = min(a, b);
		int mx = max(a, b);
		pii p = mp(mn, mx);
		if(w[p]==0){
			w[p]=x;
			n[a].pb(b);
			n[b].pb(a);
		}else{
			if(x < w[p]){
				w[p] = x;
			} 
		}
    }
    priority_queue <pli, vector<pli>, greater <pli>> q;
    q.push(mp(0,1));
    ll d[100010];
    loop(i, 100010){
		d[i] = inf;
    }
    d[1]= 0;
    set <int> visited;
    while(!q.empty()){
		pli p = q.top();
		q.pop();
		int node = p.sc;
		ll len = p.fs;
		if(visited.count(node) > 0) continue;
		visited.insert(node);
		//cout << "visiting : "  << node << endl; 
		for(auto s : n[node]){
			pii destination = mp(min(s, node), max(s, node));
			ll add = w[destination];
			if(d[s] > add + len){
				d[s] = add + len;
				q.push(mp(add+len, s));
			}
		}
	}


	//Dodajmo tire
	int rail[100010];
	bool usedRail[100010];
	loop(i, N+5) rail[i] = inf;
	loop(i, N+5) usedRail[i] = 0;
	loop(i, K){
		int a, b, x;
		cin >> b >> x;
		a = 1;
		pii p = mp(a, b);
		rail[b] = min(rail[b], x);
		if(w[p]==0){
			w[p]=x;
			n[a].pb(b);
			n[b].pb(a);
			usedRail[b] = 1;
		}else{
			if(x < w[p]){
				w[p] = x;
				usedRail[b] = 1;
			}else{
				res++;
			}
		}
	}

	//jos jedan put
	while(!q.empty()) q.pop();
	q.push(mp(0,1));
	ll nd[100010];
    loop(i, 100010){
		nd[i] = inf;
    }
    nd[1]= 0;
    visited.clear();
	vector <int> orderedNodes;
    while(!q.empty()){
		pli p = q.top();
		q.pop();
		int node = p.sc;
		ll len = p.fs;
		if(visited.count(node) > 0) continue;
		visited.insert(node);
		orderedNodes.pb(node);
		//cout << "visiting : "  << node << endl; 
		for(auto s : n[node]){
			pii destination = mp(min(s, node), max(s, node));
			ll add = w[destination];
			if(nd[s] > add + len){
				nd[s] = add + len;
				q.push(mp(add+len, s));
			}
			if(node != 1){
				if(add + len <= rail[s]){
					//cout<< "deleting " << s << endl;
					usedRail[s] = 0;
				}
			}
		}
	}
	//cout << res << endl;
	int cnt = 0;
	FOR(i,2, N+3){
		if(usedRail[i]==1) {
			cnt++;
		} 
		
    }
	//cout << "cnt " << cnt << endl;
	res +=  (K - res) - cnt;
    cout << res << endl;
    return 0;
}
