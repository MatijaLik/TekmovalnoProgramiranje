#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <string.h>
#include <math.h> 
#include<cassert>

using namespace std;
typedef long long LL;
typedef long double LD;

#define inf 999999999999;
#define FOR(i,n,m) for(LL i = n; i < m; i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (x).size()
#define all(v) (v).begin(),(v).end()
template<typename T> void PV(T v) {
	for(const auto e : v) cout<<e<<" "; cout<<endl;
}

#define print(v) for(auto e : v) cout << e << " "; cout << endl;

bool check(string curr){
	int k = 0;
	FOR(i,0,9){
		FOR(j,i+1,9){
			if(curr[i] > curr[j]){
				k++;
			}
		}
	}
	if(k%2==0) return true;
	return false;
}

vector<string> otherOptions(string curr){
	int x, y;
	FOR(i,0,9){
		if(curr[i] == '0'){
			y = i/3;
			x = i%3;
		}
	}
	int i = y*3+x;
	vector<string> ans;
	if(x > 0){
		string pt = curr;
		pt[i] = pt[i-1];
		pt[i-1] = '0';
		ans.pb(pt);
	}
	if(x < 2){
		string pt = curr;
		pt[i] = pt[i+1];
		pt[i+1] = '0';
		ans.pb(pt);
	}
	if(y > 0){
		string pt = curr;
		pt[i] = pt[i-3];
		pt[i-3] = '0';
		ans.pb(pt);
	}
	if(y < 2){
		string pt = curr;
		pt[i] = pt[i+3];
		pt[i+3] = '0';
		ans.pb(pt);
	}
	if(ans.size() > 4){
		print(ans);
	}
	assert(ans.size() <= 4);
	return ans;
}

string its(int option){
	string idk = "";
	while(idk.length() < 9){
		idk += (char)(option%10 + '0');
		option /= 10;
	}
	reverse(all(idk));
	return idk;
}

int sti(string curr){
	int ans = 0;
	FOR(i,0,9){
		ans *= 10;
		ans += curr[i]-'0';
	}
	return ans;
}

vector<int> all;

map<int, int> otn;
set<int> visit;
multiset<int> count;
vector<int> adj[200000];
int idk[] = {0,1,2,3,4,5,6,7,8}; 

void allPermutations(int s){
	if(s == 8){
		int ans = 0;
		FOR(i,0,9){
			ans *= 10;
			ans += idk[i];
		}
		string pt = its(ans);
		if(check(pt)){
			all.pb(ans);
			// auto nei = otherOptions(pt);
			// for(auto e : nei){
			// 	int nnn = sti(e);

			// 	//adj[ans].pb(nnn);
			// }
		}
		
	}else{
		FOR(i,s,9){
			int c = idk[i];
			idk[i] = idk[s];
			idk[s] = c;
			allPermutations(s+1);
			c = idk[i];
			idk[i] = idk[s];
			idk[s] = c;
		}
	}
}

int main(){
	cout<<check("123456780")<<endl;
	allPermutations(0);
	sort(all(all));
	FOR(i,0,all.size()){
		otn[all[i]] = i;
	}
	for(auto v : all){
		string curr = its(v);
		auto neibours = otherOptions(curr);
		for(auto next : neibours){
			int u = sti(next);
			adj[otn[v]].pb(otn[u]); 
		}
	}
	cout<<all.size()<<endl;
	//for(auto e : all) cout<<e<<endl;
	return 0;
}