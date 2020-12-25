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
#define inf 1000000000
#define mod 1000000007

mt19937 mt_rand(time(0));

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("input.txt", "w", stdout);
    //freopen("output.txt", "w", stdin);
    
    int limit = 200000;
    cout << limit << endl;
    loop(i, limit){
        ll pos = mt_rand();
        while(pos > i) pos /= 2;
        cout << mt_rand()/4 << " " << pos << endl;
    }
}