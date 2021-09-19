#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>
 
using namespace std;
 
#define maxn 1000011
#define fs first
#define sc second

int matching[maxn];
bool used[maxn];
vector<int> adj[maxn];

bool kuhn(int x){
	if(used[x]){
		return false;
	}

	used[x] = true;

	for(int v : adj[x]){
		if(matching[v] == -1 || kuhn(matching[v])){
			matching[v] = x;
			return true;
		}
	}
	return false;
}


int main(){
	memset(matching, -1, sizeof(matching));

	int maximum_matching = 0;
	for(int i = 0; i < n; i++){
		memset(used, 0, sizeof(used));
		maximum_matching += kuhn(i);
	}
	
	return 0;
}