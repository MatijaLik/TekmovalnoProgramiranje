#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
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
#define inf 1000000007
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 3010

ll memo[limit][limit];
ll N;
ll blocks[limit];
ll maks = 0;

ll dp(ll i, ll top){
    //cout << "dp " << i <<" " << top << endl;
    if(i == -1) return 0;
    if(memo[i][top]!= -1) return memo[i][top];
    ll ch = blocks[i];
    //previsok
    if(ch >= top){
        ll cost = ch-top;
        return memo[i][top] = cost + dp(i-1, top);// zmanjsaj
    }else if(i == 0) return memo[i][top] = 0; // zadnji
    else{//povecaj
        ll space = top-ch;
        ll mini = inf;
        FOR(add, 0, space+1){
            ll res =  add + dp(i-1, ch+add);
            if(mini > res){
                mini = res;
            }else{
                break;
            }
        }
        return memo[i][top] = mini;
    }
}

int main(){
    memset(memo, -1, sizeof memo);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    loop(i, N){
        ll temp;
        cin >> temp;
        maks = max(maks, temp);
        blocks[i] = temp;
    }
    cout << dp(N-1, maks) << endl;

}