#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 1000010

ll nums[limit];
ll r[limit];
ll parent[limit];

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

priority_queue <ll> q[limit];


void un(ll x, ll y){
    ll xRoot = find(x);
    ll yRoot = find(y);
    if(r[xRoot]<r[yRoot]){
        ll temp = yRoot;
        yRoot = xRoot;
        xRoot = temp;
    }
    parent[yRoot] = xRoot;
    if(r[xRoot] == r[yRoot]) r[xRoot]++;
}


int main(){
    ll N, M;
    cin >> N >> M;
    loop(i, N){
        cin >> nums[i];
        parent[i+1] = i+1;
    }
    loop(i, M){
        ll a, b;
        cin >> a>> b;
        un(a,b);
    }
    loop(i, N){
        q[find(i+1)].push(nums[i]);
    }
    loop(i, N){
        cout << q[find(i+1)].top() << " ";
        q[find(i+1)].pop();
    }
    cout << endl;
    return 0;
}