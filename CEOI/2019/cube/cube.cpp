/**
 * Author: MatijaL
 * Time: 2021-08-28 18:29:13
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
#define print(v) for(auto e : v) cout << e << " "; cout << endl;



int hsh(char c){
    if(c >= 97) return c - 97;
    if(c >= 65) return c - 65 + 25;
    return c;
}

void solve(){

    ll A[11][58][58];
    const ll mod = 998244353;
    
    int n;
    cin >> n;
    set<string> S[11];
    set<string> vse;
    loop(i, n){
        string s;
        cin >> s;
        //printf("%d %d\n", hsh(s.front()), hsh(s.back()));
        if(vse.count(s) == 0) A[s.length()][hsh(s.front())][hsh(s.back())]++;
        vse.insert(s);
        reverse(all(s));
        if(vse.count(s) == 0) A[s.length()][hsh(s.front())][hsh(s.back())]++;
        vse.insert(s);
    }

    pair<int, int> stranice[12] = { 
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
        };
    

    ll ans = 0;

    FOR(len, 3, 10){
        FOR(m, 0, pow(6, 8)-1){
            ll mcp = m;
            ll prod = 1;
            int msk[8];
            loop(i, 8){
                msk[i] = mcp % 6;
                mcp /= 6;
            } 
            //vse stranice
            loop(i, 12){
                prod *= A[len][msk[stranice[i].fs]][msk[stranice[i].sc]];
                prod %= mod;
            }

            ans += prod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
