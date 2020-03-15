#include<iostream>
#include<queue>

using namespace std;
int n, k, sum;
//Dvojni podatki niso ravno časovno učinkoviti
//
bool use[301];
queue <pair<int,pair<int, int>>> q;
void add(int a, int b, int c, bool loud, int  (&d) [301][301]){
    	if(d[a][b]<=c) {
		cout << sum << endl;
		return;
	}
	if(loud){
	    for(int i = 1; i <= n; i++){
		use[i]=0;
	    }
	    use[a] = 1;
	    use[b] = 1;
	}else{
	    use[b] = 1;
	}
	sum -= d[a][b]-c;
	d[a][b]=c;
	d[b][a]=c;
	for(int i=1;i<=n;i++){
    		//if(use[i]) continue;
		int ci1 = d[a][i];
		int ci2 = d[b][i];
		//cout << ci1 <<"-"<<ci2<<endl;
		if(ci1+c < ci2){
		    //add(b, i, ci1+c, 0, d);
		    q.push(make_pair(b,make_pair(ci1+c, i)));
	    	}else if(ci2 + c < ci1){
		    //add(a, i, ci2+c, 0, d);
		    q.push(make_pair(a, make_pair(ci2+c, i)));
		}
	}
	if(!q.empty()){
	    pair<int, pair<int, int>> p = q.front();
	    q.pop();
	    add(p.first, p.second.second, p.second.first, 0, d);
	}
	if(loud)cout << sum <<" ";
}
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int d[301][301];
	for(int i=1; i<=n;i++) for(int j=1;j<=n;j++){
		int temp;
		cin >> temp;
		d[i][j] = temp;
		if(i>j) sum+= temp;
		
	}
	cin >> k;
	for(int i=0; i<k;i++){
		int a, b, c;
		cin >> a>> b>>c;
		add(a,b,c,1,d);
	}
	cout << endl;
	return 0;
}
