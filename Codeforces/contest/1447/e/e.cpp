/**
 * Author: MatijaL
 * Time: 2020-11-15 15:35:01
**/

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
#define inf 1000000005
#define mod 1000000007

#define limit 200100

ll parent[limit];
ll sz[limit];
bool good[i];

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void un(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    good[x] = good[x] or good[y];
}


void solve(){

    loop(i, limit){
        good[i] = false;
        parent[i] = i;
        sz[i] = 1;
    }

    int n;
    cin >> n;
    
    vector<ll> v(n);
    loop(i, n) cin >> v[i];
    sort(all(v));


    set<pll> link;

    loop(i, n){
        ll l = 0;
        ll r = n-1;

        ll A;
        A = v[i];

        //printf("looking for %d\n", A);
        ll cum = 0;

        for(ll bit = 31; bit >= 0; bit--){

            ll pivot = lower_bound(all(v), cum + (1LL << bit)) - v.begin();
            if(l == r) break;
            bool on = A & (1LL << bit);
            if(on){
                //probaj dat l na pivot
                if(r != i or r != pivot){
                    l = pivot;
                    cum += (1LL<<bit);
                }else{
                    //nic
                    r = min(pivot-1, r);
                }
            }else{
                //probaj dat r na pivot
                if(l != i or pivot -1 != l){
                    r = min(pivot-1, r);
                }else{
                    //nic
                    l = pivot;
                    cum += (1LL<<bit);
                }
            }
            //printf("%lld %lld\n", l, r);
        }

        
        //printf("%lld\n", v[l]);
        un(i, l);

        //cout << sz[find(i)] << endl;
    }

    

    set<int> comps;
    vector<int> c;
    loop(i, n){
        if(comps.count(find(i))==0){
            comps.insert(find(i));
            c.pb(find(i));
        }
    }

    ll mx = 0;
    ll sum = 0;
    for(auto e : c){
        //cout << sz[e] << " ";
        //cout << endl;

        mx = max(sz[e]-1, mx);
        sum += sz[e]-1;
    }
    cout << sum-mx << endl;
    return;
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
