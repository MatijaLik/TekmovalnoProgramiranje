/**
 * Author: MatijaL
 * Time: 2020-10-17 18:07:15
**/

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
#define inf 100000000005
#define mod 1000000007
int N, M;
string scary;
string fav;

map<char, vector<int>> indeces;

ll memo[1000][1000];
ll dp(int p, int c){
    if(memo[p][c] != -1) return memo[p][c];
    if(c >= M) return 0;
    memo[p][c] = -2; //temp
    char need = fav[c];

    ll best = inf;


    //skocimo
    char cur = scary[p];

    vector<int> possible = indeces[cur];
    for(auto e : possible){
        if(e > 0 and scary[e-1] == need) best = min(best,abs(e-p)+ 1+dp(e-1, c+1));
        if(e < N and scary[e+1] == need) best = min(best, abs(e-p)+1+dp(e+1, c+1));
    }
    return memo[p][c] = best;
}

void solve(){
    memset(memo, -1, sizeof memo);
    cin >> N >> M;
    cin >> scary;
    cin >> fav;
    loop(i, scary.size()){
        char c = scary[i];
        indeces[c].pb(i);
    }

    ll best = inf;
    loop(i, scary.size()){
        if(scary[i] == fav[0])
        best = min(best, dp(i, 1));
    
    }
    if(best >= inf-100) cout << -1 << endl;
    else cout << best << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
   solve();   
}
