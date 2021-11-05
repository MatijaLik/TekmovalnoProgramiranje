#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;
 
#define limit 100200
#define DEBUG 0
const ll INF = inf*1LL*inf;

//hamming distance

int n, k;

void pocasiResitev(){
    vector<int> v;
    loop(i, n){
        string s;
        cin >> s;
        int num = 0;
        loop(i, s.length()){
            char e = s[i];
            num *= 2;
            if(e == '1') num += 1; 
            
        }v.pb(num);
    }

    int mini = inf;
    loop(i, v.size()){
        FOR(j, i+1, v.size()-1){
            int dist = 0;
            mini = min(mini, __builtin_popcount(v[i]^v[j]));
        }
    }

    cout << mini << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    


    pocasiResitev();
    


    return 0;
}