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


ll random(ll mini, ll maxi){
    int range = maxi - mini + 1;
    int num = rand() % range + mini;
    return num;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    cout << 2000 << endl;
    loop(i, 2000){
        cout << random(-inf, inf) << " ";
        cout << random(-inf, inf) << " ";
        cout << random(1, inf) << endl;
    }
}