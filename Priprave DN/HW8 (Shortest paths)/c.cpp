#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>
#define pii pair<int, int>
#define mp make_pair
#define inf 1000000000000
#define pb push_back
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int m;
    cin >> m;

    map <pii, int> cost;
    set <int> visited;
    priority_queue <pli> q;
    ll d[n+10];
    map <int, vector <int>> s;
    int pr[n+10];

    for(int i =0; i < n+10; i++){
	d[i] = inf;
    }


    for(int i=0; i < m; i++){
	int a, b, w;
	cin >> a >> b >> w;
	s[a].pb(b);
	s[b].pb(a);
	cost[mp(min(a,b), max(a,b))] = w;
    }
    q.push(mp(0,1));
    while(true){
		if(q.empty())break;
		pli p = q.top();
		q.pop();
		int node = p.second;
		//cout << "visited " << node << endl;
		ll dis = -(p.first);
		if(node==n) break;
		if(visited.count(node)>0) continue;
		visited.insert(node);
		for(auto sosed : s[node]){
			int c = cost[mp(min(node,sosed), max(node, sosed))];
			if(visited.count(sosed)==0) if(dis+c < d[sosed]) {
			q.push(mp(-(dis+c), sosed));
			//cout << "pushing " << sosed << " with cost " << dis + c << endl; 
			d[sosed] = dis+c;
			pr[sosed] = node;
			}
		}
    }

    //dijsktra();
    if(d[n] == inf) cout << -1 << endl;
    else{
	vector <int> path;
	int cur = n;
	path.pb(n);
	while(cur!=1){
	    cur = pr[cur];
	    path.pb(cur);
	}
	reverse(path.begin(), path.end());
	for(auto e : path){
	    cout << e << " ";
	}	
	cout << endl;
    }
    
    return 0;
}

