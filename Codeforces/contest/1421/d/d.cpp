/**
 * Author: MatijaL
 * Time: 2020-10-18 13:06:57
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

void solve(){
    ll x, y;
    cin >> x >> y;
    vector<ll> c(6);
    loop(i, 6) cin >> c[i];

    FOR(i, 1, 6){
        c[i%6] = min(c[i%6], c[i-1]+ c[(i+1)%6]);
    }
    if(x == 0 and y == 0) return 0;
    if(x > 0 and y > 0){
        ll best = inf*inf;

        //1
        ll t = 0;
        if(x > 0) t += x*c1;
        else t += abs(x)*c4;

        if(x <= y) t += (y-x)*c2;
        else t += (x-y)*c5;

        best = min(best, t);

        //2
        t = 0;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)cout <<  solve() << endl;   
}
