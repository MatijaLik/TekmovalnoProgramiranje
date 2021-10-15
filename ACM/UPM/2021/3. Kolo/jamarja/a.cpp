#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n, m) for(int i = n; i <= m; i++)
#define loop(i, n) FOR(i, 0, n-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define sc second
#define fs first
 #define limit 100500
int par[limit];
int z[limit];
int sz[limit];
int n;
pll val[limit];
 
 vector<int> kids[limit];
 
 
 bool diffSort(pll a, pll b){
 	return a.fs - a.sc > b.fs - b.sc;
 }
 
 pll dfs(int node){
    sz[node] = 1;
 	int p = z[node]; 
 	int q = 0;
 	vector<pll> sodi;
 	vector<pll> lihi;
 	for(auto e : kids[node]){
 		pll d = dfs(e);
        sz[node] += sz[e];
 		if(sz[e] % 2 ==0) sodi.pb(d);
 		else lihi.pb(d);
	 }
     //1. vsi sodi z negativno razliko
     //2. izmenicno ta lihe
     //3. ostale ta sode
	 
	 //sestavi skup
     sort(all(sodi), diffSort);
     reverse(all(sodi));
     int ie = 0;
	 while(ie < sodi.size()  and sodi[ie].fs <= sodi[ie].sc){
         p += sodi[ie].fs;
         q += sodi[ie].sc;
         ie++;
     }

	 sort(all(lihi), diffSort);
     reverse(all(lihi));
	 int flip = 0;
	 for(auto e : lihi){
         //if(lihi.size() >= 2) printf("%d %d\n", e.fs, e.sc);
         if(!flip){
            p += e.fs;
            q += e.sc;
         }else{
             p += e.sc;
             q += e.fs;
         }
	 	flip = 1-flip;
      
	 }
     //vse ostale
     for(; ie < sodi.size() ;ie++){
         if(!flip){
             p += sodi[ie].fs;
             q += sodi[ie].sc;
         }else{
             q += sodi[ie].fs;
             p += sodi[ie].sc;

         }
     }
     //printf("node %d| %lld %lld\n", node, p, q);
	 return mp(p, q);
 }
 
 
int main(){
	int n;
	cin >> n;
	loop(i, n){
		cin >> par[i+1];
		kids[par[i+1]].pb(i+1);
	}
	loop(i, n) cin >> z[i+1];
	
	
	pll p = dfs(1);
    cout << p.fs << " " << p.sc << endl;
}
