#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

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

void solve(){
    int N;
    cin >> N;
    vector<int> v(N+1, 0);

    ll ans=0;

    set<int> barve;
    loop(i, N){
        cin >> v[i+1];
        barve.insert(v[i+1]);
    }

    map<int, ordered_set> M;
    map<int, int> cumSum;
    FOR(r, 1, N){
        int cur = v[r];
        cumSum[cur]++;

        //Dodaj not
        if(!M.count(cur)){
            M[cur] = ordered_set();
            M[cur].insert(mp(0,0));
        }

        //Preveri vse
        for(auto const& [color, ord_s] : M){
            int res = ord_s.order_of_key(mp(2*cumSum[color]-r,0));
            ans += res;
            if(res==0){
                M.erase(color);
            }
        }
        M[cur].insert(mp(2*cumSum[cur]-r, r));
    }
    /*
    for(auto e : barve){
        int cum = 0;
        ordered_set cums;
        cums.insert(mp(0, 0));

        FOR(i, 1, N){
            if(v[i]==e)cum++;
            int res = cums.order_of_key(mp(2*cum-i,0));
            ans += res;

            cums.insert(mp(2*cum-i, i));
        }
    }*/
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}