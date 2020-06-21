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
#define pli pair<long long, ll>
#define vi vector <ll>
#define pis pair<int, string>
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
pis memo[25][200100];
int kandid[25];
int vecina;

pis dp(int i, int ps){
    if(memo[i][ps] != mp(-1, (string)"")) return memo[i][ps];
    if(i==N){
        if(ps > vecina) return memo[i][ps] = mp(0, "");
        else return memo[i][ps] = mp(inf, "");
    }
    int cur = kandid[i];
    pis dp1 = dp(i+1, ps+cur);
    pis dp2 = dp(i+1, ps);
    if(dp1.fs + cur <= dp2.fs){
        return memo[i][ps] = mp(dp1.fs+cur, dp1.second  + to_string(i+1)+ " ");
    }else return memo[i][ps] = mp(dp2.fs, dp2.second);
}

int main(){
    loop(i, 25)loop(j, 200100) memo[i][j] = mp(-1, (string)"");
    cin >> N;
    vector<int> v;
    double sum = 0;
    loop(i, N){
        int temp;
        cin >> temp;
        sum += temp;
        v.pb(temp);
    }
    vecina = sum/2.0;
    loop(i, N){
        kandid[i] = v[i];
    }
    cout << dp(0,0).second << endl;
    
}