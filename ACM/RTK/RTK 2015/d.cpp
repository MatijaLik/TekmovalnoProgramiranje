
// C++ program to demonstrate working of Meet in the 
// Middle algorithm for maximum subset sum problem. 
#include <bits/stdc++.h> 
#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


typedef long long int ll; 
vector<ll> u, v; 
vector<ll> a, b;

int main() 
{   
    ll N, M;
    cin >> N >> M;
    ll k = N/2;
    loop(i, N){
        ll temp;
        cin >> temp;
        if(i < k) a.pb(temp);
        else b.pb(temp);
    }
    for(int i = 0; i < (1<<k); i++){
        ll sum = 0;
        loop(j, k){
            if((1 << j) & i){
                sum+=a[j];
            }
        }
        u.pb(sum);
    }
    for(int i = 0; i < (1<<N-k); i++){
        ll sum = 0;
        loop(j, N-k){
            if((1 << j) & i){
                sum+=b[j];
            }
        }
        v.pb(sum);
    }
    sort(all(u));
    sort(all(v));
    /*
    printf("####\n");
    for(auto h : u){
        printf("%d\n", h);
    }
    printf("####\n");
    for(auto h : v){
        printf("%d\n", h);
    }
    printf("####\n");
`   */
    while(M--){
        ll q;
        cin >> q;
        ll pv = (1 << N-k)-1;
        ll sum;
        ll best = 0;
        for(ll pu = 0; pu < (1 << k); pu++){
            sum = u[pu];
            if(sum > q) break;
            while(sum + v[pv] > q) pv--;
            best = max(sum + v[pv], best);
        }
        cout << best << endl;
    }
    
    return 0; 
} 