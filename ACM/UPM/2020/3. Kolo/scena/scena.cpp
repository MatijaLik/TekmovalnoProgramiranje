/**
 * Author: MatijaL
 * Time: 2020-10-01 19:17:11
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define pdd pair<double, double>
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

const int EPS = 0.001;

bool isEqual(double a, double b){
    return abs(a-b) < EPS;
}

int N, M;

vector<pll> zvezde;
vector<pll> trikotniki;

vector<pll> vse;

    

void solve(){
    cin >> N >> M;
    loop(i, N){
        double x, y;
        cin >> x >> y;
        zvezde.pb(mp(2*x - x, 2*x - y));
    }

    loop(i, M){
        double x, y;
        cin >> x >> y;
        trikotniki.pb(mp(2*x + y, 2*x - y));

    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
