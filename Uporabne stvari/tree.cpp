
//HEAVY-LIGHT DECOMPOSITION

vector<int> parent, heavy, head, pos, depth;
vector<int> children[limit];
int curPos=1;
 
int dfs(int node){
	int size = 1;
	int maxS = 0;
	int best = -1;
	for(int c : children[node]){
		depth[c] = depth[node] + 1;
		int ret = dfs(c);
		size += ret;
		if(maxS < ret){
			best = c;
			maxS = ret;
		}
	}
		
	//nastavi heavy edge
	heavy[node] = best;
 
	return size;
}
 
void decompose(int node, int h){
	if(DEBUG)printf("decom %d, heavy %d\n", node, heavy[node]);
	head[node] = h;
	pos[node] = curPos++;
	
	if(heavy[node] != -1) decompose(heavy[node], h); //isti component
	for(int c : children[node]){
		if(c == heavy[node]) continue;
		decompose(c, c);
	}
}
