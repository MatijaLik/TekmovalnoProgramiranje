/**
 * Author: MatijaL
 * Time: 2021-06-28 21:02:39
**/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


/*

set fast optimization
erase log 

*/

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
//#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;



void solve(){
    int n, k;
    cin >> n >> k;
    

    ordered_set s;
    loop(i, n) s.insert(i+1);

    int id = 0;
    while(n){
        id += k;
        id %= n;

        auto it = s.find_by_order(id);

        printf("%d ", *it);

        s.erase(it);

        n--;
    }
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
