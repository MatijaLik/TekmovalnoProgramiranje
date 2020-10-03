struct Edge
{
    int from, to, weight;
    bool operator<(Edge other) const
    {
        return weight > other.weight;
    }
};

struct TestStruct {
    int id;
    double number; 
    TestStruct(int anInt, double aDouble) : id(anInt), number(aDouble) { }
};

ios::sync_with_stdio(0);
cin.tie(0);

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

ll HASH(string a){
    ll len = a.length();
    ll out = 0;
    for(ll i = 0; i<len; i++){
        out = ((out*26) + (a[i] - 'A')) % mod;
    }
    return out;
}

q.push(mp(0,1));//dijkstra
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