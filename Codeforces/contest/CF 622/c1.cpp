#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

ll N;
ll M[1010];
ll tempConf[1010];
ll optConf[1010];

ll right(ll id){
    ll cnt = 0;
    ll top = M[id];
    for(ll i = id+1; i < N; i++){
        top = min(top, M[i]);
        cnt += top;
        //cout << 'h' << top << endl;
        tempConf[i] = top;
    }
    return cnt;
}
ll left(ll id){
    ll cnt = 0;
    ll top = M[id];
    for(ll i = id-1; i >= 0; i--){
        top = min(top, M[i]);
        cnt += top;
        tempConf[i] = top;
    }
    return cnt;
}

int main(){
    cin >> N;
    //ll mx = 0;
    loop(i, N){
        cin >> M[i];
        //mx = max(mx, M[i]);
    }
    ll maxRes = 0;
    loop(i, N){
        ll tempRes = 0;
        if(1){
            tempConf[i] = M[i];
            tempRes += M[i];
            tempRes += right(i);
            tempRes += left(i);
        }
        if(tempRes > maxRes){
            maxRes = tempRes;
            copy(begin(tempConf), end(tempConf), begin(optConf));
        }
    }
    loop(i, N){
        cout << optConf[i] << " ";
    }
    cout << endl;
}