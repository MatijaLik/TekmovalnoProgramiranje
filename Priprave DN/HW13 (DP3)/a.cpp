#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl

#define nlimit 102
#define mlimit 10100

int N, M;


vector<int> police[nlimit];
short memo1[nlimit][nlimit][nlimit][nlimit];

int dp1(int n, int k, int l , int r){
    if(memo1[n][k][l][r]!=0) return memo1[n][k][l][r];
    if(k==0) return 0;
    if(l > r) return 0;

    int top = 0;
    top = max(top, police[n][l] + dp1(n, k-1, l+1, r));
    top = max(top, police[n][r] + dp1(n, k-1, l, r-1));

    return memo1[n][k][l][r] = top;
}

int memo2[nlimit][mlimit];

int dp2(int n, int rem){
    if(memo2[n][rem]!=0) return memo2[n][rem];
    if(n == N) return 0;
    if(rem==0) return 0;
    if(rem < 0) return -inf;

    int top = 0;
    int maxSize = min(rem, (int)police[n].size());
    FOR(i, 0, maxSize){
        top = max(top, memo1[n][i][0][police[n].size()-1] + dp2(n+1, rem - i));
    }

    return memo2[n][rem] = top;
}

int main(){
    cin >> N >> M;
    loop(i, N){
        int amnt;
        cin >> amnt;
        loop(j, amnt){
            int temp;
            cin >> temp;
            police[i].pb(temp);
        }

        //izvedi dp
        FOR(j, 0, amnt){
            dp1(i, j, 0, amnt-1);
        }
    }
    cout << dp2(0, M) << endl;
}