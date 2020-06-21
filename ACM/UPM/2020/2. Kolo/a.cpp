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
 
int main(){
    string s = "Oops!";
    int n;
    cin>>n;
    int m = n;
    do{
        cout<<--m<<endl;
        cin>>s;
    }while(s != "Bingo!" && m);
    m = n;
    if(m % 2 == 0) cout<<0<<endl;
    cin>>s;
    if(s == "Bingo!") return 0;
    do{
        cout<<--m<<endl;
        cin>>s;
    }while(s != "Bingo!");
}