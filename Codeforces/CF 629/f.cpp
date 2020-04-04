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
#define debug(x) cout << "# " << x << endl;

#define nlimit 200010

set<ll> s;
vector<ll> v;
map<ll, ll> m;

ll cumSum[nlimit];

ll N, K;

int main(){
    cin >> N >> K;
    loop(n, N){
        ll temp;
        cin >> temp;
        if(s.count(temp)==0){
            s.insert(temp);
            v.pb(temp);
        }
        m[temp]++;
    }
    ll len = v.size();
    sort(all(v));
    cumSum[len]= 0;
    for(ll i = len-2; i >= 0; i--){
        cumSum[i] = (m[i+1]+cumSum[i+1])*(v[i+1]-v[i]) + cumSum[i+1];
        //printf("i %d; dif %d\n", i, v[i+1]-v[i]);
    }
    FOR(i, 0, N-1)cout << cumSum[i] << " ";
    cout << endl;

}