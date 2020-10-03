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
#define loop(i, n) for(ull i = 0; i < n; i++)
#define FOR(i,n,m) for(ull i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
 
#define limit 64
 
ull ans[30000000];
 
 
int main(){
    ull u, v;
    cin >> u >> v;
    if(u > v){
        cout << -1 << endl;
        return 0;
    }
    ull rem = v-u;
    ull buffer = 0;
    ans[0] = u;
    for(ll i = limit; i >= 0; i--){
        buffer *= 2;
        ull ud = u&((ull)1 << i);
        ull ur = rem&((ull)1 << i);
        //printf("index %d, ud is %d, ur is %d- current buffer: %d\n", i, (bool)ud, (bool)ur, buffer);
        if(ud == 0){
            loop(h, buffer){//pocisti
                ans[h] += ((ull)1 << i);
            }
            buffer = 0;
            if(ur) buffer = 1;
        }else{
            //primer 1 - 1
            if(ur){
                buffer += 1;
            }else{
                FOR(h,1, buffer+1){//pocisti
                    ans[h] += ((ull)1 << i);
                }
                buffer = 0;
            }
        }
    }
    if(buffer){
        cout << -1 << endl;
        return 0;
    }
    //cout << "stop " << endl;
    ull i = 0;
    while(ans[i] != 0){
        i++;
    }
    cout << i << endl;
    loop(t, i){
        cout << ans[t] << " ";
    }
    if(i)cout << endl;
}