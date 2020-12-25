/**
 * Author: MatijaL
 * Time: 2020-11-30 08:27:22
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
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

#define T 1000

void solve(){
    long double N, k;
    cin >> N >> k;
    
    vector<long double> base(T+10);
    vector<long double> step(T+10);

    FOR(n, 1, N){
        FOR(t, 1, T){
            step[t] = ((k-1)/k)*base[t] + 1/(k*(t+1))*( (t*(t+3))/2 + base[t+1] + t*base[t]);
        } 
        base = step;
    }

    printf("%.10Lf\n", k*base[1]);
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
