/**
 * Author: MatijaL
 * Time: 2020-10-01 16:31:43
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
    vector<int> ulam;
    int a, b;

    int N;
    cin >> N;
    cin >> a >> b;

    int sn[1001000];

    memset(sn, 0, sizeof sn);

    sn[a] = 1;
    sn[b] = 1;
    ulam.pb(a);
    ulam.pb(b);
    if(a + b <=  N) sn[a+b] = 1;
    FOR(i, b+1, N){
        if(sn[i] > 1) continue;
        if(sn[i] == 0) continue;
        if(sn[i] == 1){
            
            for(auto e : ulam){
                if( e + i > N) break;
                sn[i+e]++;
            }
            ulam.pb(i);
        }
        if(ulam.size() > 10100) break;
    }


    for(auto e : ulam)cout << e << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
