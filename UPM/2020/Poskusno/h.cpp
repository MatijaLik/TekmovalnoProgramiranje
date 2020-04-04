
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

bool sito[32000];
vector<LL> primes;
 
void cito(){
	FOR(i,0,32000) sito[i] = true;
	sito[0] = 0;
	sito[1] = 0;
	FOR(i,2,32000){
		if(sito[i]){ 
			for(LL j = i*i; j < 32000; j+=i){
				sito[j] = false;
			}
		}
	}
	FOR(i,0,32000) if(sito[i]) primes.pb(i);
}

pair<LL,LL> fact(LL n){
	LL i = 0;
	LL p = primes[i];
	multiset <LL> ms;
	set <LL> s;
	while(p*p <= n){
		while(n % p == 0){
			n /= p;
			ms.insert(p);
			s.insert(p);
		}
		p = primes[++i];
	}
	if(n != 1){
		ms.insert(n);
		s.insert(n);
	}
	LL a = 1, b = 1;
	for(auto e : s){
		LL pt = ms.count(e)/2;
		while(pt){
			a *= e;
			pt--;
		}
		if(ms.count(e)%2==1){
			b *= e;
		}
	}
	return mp(a,b);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    cito();
	int T;
	cin>>T;
	while(T--){
		LL a = 0;
		LL b = 0;
		string s;
		cin>>s;
		if(s[0]=='s'){
			int i = 5;
			while(i != s.size() && s[i] != ')'){
				b *= 10;
				b += s[i]-'0';
				i++;
			}
		}else{
			int i = 0;
			while(i != s.size() && s[i] != '*'){
				a *= 10;
				a += s[i]-'0';
				i++;
			}
			if(i != s.size()){
				i += 6;
				while(i != s.size() && s[i] != ')'){
					b *= 10;
					b += s[i]-'0';
					
					i++;
				}
			}
		}
		if(!a) a = 1;
		pair<LL,LL> pt = fact(b);
		a = a * pt.fs;
		b = pt.sc;
		if(a == 1){
			cout<<"sqrt("<<b<<")";
		}else{
			cout<<a;
			if(!(b == 0 or b == 1)){
				cout<<"*sqrt("<<b<<")";
			}
		}
		if(T>0) cout<<endl;
	}
}