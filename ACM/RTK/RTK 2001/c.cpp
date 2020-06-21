#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pis pair<int, string>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


int N;
vector <int> v;
double vecina = 0;
pis memo[23][200100];

pis dp(int i, int ps){
    //cout << "DP " << i << " " << ps << endl;
    if(i==N){
        if(ps <= vecina) return mp(inf, "");
        else return mp(0, "");
    }
    if(memo[i][ps] != mp(-1, (string) "")){
        //cout << "memo" << endl;
        return memo[i][ps];
    } 


    int cur = v[i];
    //dve opciji
    //1. gre v koalicijo
    pis p1 = dp(i+1, ps+cur);

    //2. Luka Mesec
    pis p2 = dp(i+1, ps);


    //cout << "DP " << i << " " << ps <<" RES" << endl;
    if(p1.first < p2.first){
        //cout << "add" << endl;
        return memo[i][ps] = mp(p1.first+cur, p1.second + to_string(i+1)+ " " ) ;
    }else{
        //cout << "skip" << endl;
        return memo[i][ps] = mp(p2.first, p2.second);
    }

}
int main(){
    loop(i, 23) loop(j, 200100) memo[i][j] = mp(-1, "");
    cin >> N;
    ll sum = 0;
    loop(i, N){
        int temp;
        cin >> temp;
        v.pb(temp);
        sum += temp;
    }
    vecina = (double)sum/(double)2;
    //cout << vecina << endl;
    cout << dp(0, 0).second << endl;
}
