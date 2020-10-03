/**
 * Author: MatijaL
 * Time: 2020-09-09 08:32:43
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
#define limit 205
int N, K;
string s;
char a, b;
int memo[limit][limit][limit];

int dp(int pos, int rem, int acnt){
    if(memo[pos][rem][acnt] != -1) return memo[pos][rem][acnt];
    if(rem == -1) return -inf;
    if(pos == N) return 0;

    /*
     * 1 - nic ne narei
     * 2 - dodaj a
     * 3 - dodaj b
     */
    char c = s[pos];
    int mx = 0;
    //1
    if(c == a) mx = max(mx, dp(pos+1, rem, acnt+1));
    if(c == b) mx = max(mx, acnt + dp(pos+1, rem, acnt));
    if(c == a and a == b) mx = max(mx, acnt + dp(pos+1, rem, acnt+1));
    mx = max(mx, dp(pos+1, rem, acnt));

    //2
    if(c != a) mx = max(mx, dp(pos+1, rem-1, acnt+1));
    if(c != a and a == b) mx = max(mx, acnt + dp(pos+1, rem-1, acnt+1));

    //3 
    if(c != b) mx = max(mx, acnt+dp(pos+1, rem-1, acnt));
    //printf("%d %d %d -> %d\n", pos, rem, acnt, mx);
    return memo[pos][rem][acnt] = mx;
}

void solve(){
   //nastavi memo
   loop(i, limit) loop(j, limit) loop(k, limit) memo[i][j][k] = -1;
   cin >> N >> K;
   cin >> s;
   string temp;
   cin >> temp;
   a = temp[0];
   b = temp[1];

   cout << dp(0, K, 0) << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
