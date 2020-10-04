#include "testlib.h"
#include <cassert>
using namespace std;

const int MAXR = 10;
const int MAXLOGN = 10;
const int MAXN = 1000;
const int MAXQ = 100000;
const int MAXK = 1e9;

int union_find_parent[MAXN];
vector<int> adj_list[MAXN];
int dfs_parent[MAXN][MAXLOGN], node_depth[MAXN];

// find_leader function for union-find
int find_leader(int k) { 
	return union_find_parent[k] = union_find_parent[k] == k ? k : find_leader(union_find_parent[k]); 
}

// dfs for 2k-decomposition
void dfs(int node, int parent, int depth) {
	node_depth[node] = depth;
	dfs_parent[node][0] = parent;
	for (int i = 1; i < MAXLOGN; i++) {
		dfs_parent[node][i] = dfs_parent[dfs_parent[node][i - 1]][i - 1];
	}
	for (int i : adj_list[node]) {
		if (i == parent) continue;
		dfs(i, node, depth + 1);
	}
}

// find neighbour when traveling from source to destination
int find_neighbour(int source, int dest) {
	// if source is not ancestor of dest, answer is parent of source
	if (node_depth[dest] <= node_depth[source]) { 
		return dfs_parent[source][0];
	}
	
	// find ancestor of dest with depth (node_depth[source] + 1)
	for (int i = 0; i < MAXLOGN; i++) {
		if ((node_depth[dest] - node_depth[source] - 1) & (1 << i)) {
			dest = dfs_parent[dest][i];
		}
	}
	
	// if dest is now direct child of source, answer is dest
	if (dfs_parent[dest][0] == source) {
		return dest;
	}
	
	// otherwise, dest is not in subtree, move to parent
	return dfs_parent[source][0];
}

int main() {
	registerValidation();
	int r = inf.readInt(1, MAXR, "r");
	inf.readEoln(); 
	int total = 0;
	for (int i = 0; i < r; i++) {
		// read tree
		int n = inf.readInt(2, MAXN, "n");
		inf.readSpace();
		int k = inf.readInt(n, MAXK, "k");
		inf.readEoln();
		for (int j = 0; j < n; j++) {
			union_find_parent[j] = j;
			adj_list[j].clear();
		}
		for (int j = 0; j < n - 1; j++) {
			int u = inf.readInt(0, n - 1, "u_i");
			inf.readSpace();
			int v = inf.readInt(0, n - 1, "v_i");
			inf.readEoln();
			ensuref(u != v, "self-edge in tree in index %d", i);
			int p1 = find_leader(u), p2 = find_leader(v);
			ensuref(p1 != p2, "edges do not form a tree in index %d", i);
			union_find_parent[p1] = p2;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		
		// run 2k-decomp to find answers later
		memset(dfs_parent, 0, sizeof(dfs_parent));
		dfs(0, 0, 0);
		
		// read queries
		int q = inf.readInt(1, MAXQ, "q");
	  inf.readEoln();
	  for (int j = 0; j < q; j++) {
	  	int s = inf.readInt(0, n - 1, "s_j");
	  	inf.readSpace();
	  	int t = inf.readInt(0, n - 1, "t_j");
	  	inf.readSpace();
	  	int ans = inf.readInt(0, n - 1, "ans_j");
	  	inf.readEoln();
	  	ensuref(s != t, "same source and destination vertex in query %d of index %d", j, i);
			ensuref(find_neighbour(s, t) == ans, "wrong answer %d in query %d of index %d should be %d", ans, j, i, find_neighbour(s, t));
	  	total += adj_list[s].size();
	  }
	}
	ensuref(total <= MAXQ, "total size of all queries exceeds %d", MAXQ);
	
	// read is_partial and shuffle seed
	inf.readInt(0, 1, "is_partial");
	inf.readSpace();
	inf.readInt(0, INT_MAX, "seed");
	inf.readEoln();
	inf.readEof();
	return 0;
}
