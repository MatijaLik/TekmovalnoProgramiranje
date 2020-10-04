/**
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
#define inf 1000000005
#define mod 1000000007

#define nlimit 1005
#define klimit 105
const long long INF = 1e13;
ll N, K;
pll smeti[nlimit];//1 indexed
ll memo[nlimit][nlimit][klimit];

ll dp(int pos, int prev, int stackNum){
    if(memo[pos][prev][stackNum] != -1) return memo[pos][prev][stackNum];
    if(pos == N+1){
        if(stackNum > K) return memo[pos][prev][stackNum] = INF;
        if(prev != N) return memo[pos][prev][stackNum] = INF; //se vedno nosimo
        return memo[pos][prev][stackNum] = 0; //smo koncali
    }

    //ce ne rabimo vec prenasat:wq
    //
    int trashLeft = N - pos + 1;
    if(stackNum + trashLeft <= K) return memo[pos][prev][stackNum] = 0;

    ll best = INF;

    //odlozimo
    //to gre, samo ce naslednji trash ni na isti poziciji
    if(pos == N  or  smeti[pos+1].fs != smeti[pos].fs)
        best = min(best, dp(pos+1, pos, stackNum + 1);

    //vzamemo v roke
    if(pos != N){
        ll totalWeight = rs[pos] - rs[prev];
    }

    //damo na levo
    if(prev != -1){
        ll weight = smeti[pos].sc;
        ll dist = smeti[pos] 
    }
        best = min(best, 
}
void solve(){

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();
}
