/**
 * Author: MatijaL
 * Time: 2022-04-17 23:25:04
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
#define print(v) for(auto e : v) cout << e << " "; cout << endl;


const int maxN = 200500;

struct FenwickTree{
    int a[maxN];
    
    void add(int id, int val){
        for(; id<maxN; id += id & -id)
            a[id] += val;
    }
    int query(int id){
        int ans=0;
        for(; id > 0; id -= id & -id)
            ans += a[id];
        return ans;
    }
    
    int range_query(int l, int r){
        return query(r) - query(l-1);
    }
    
};

void solve(){
    //FenwichTree FT;
    int cnt[maxN];
    memset(cnt, 0, sizeof cnt);
    
    set<int> vsi;
    int N, K;
    cin >> N >> K;
    vector<int> v(N, 0);
    

    loop(i, N){
        cin >> v[i];
        vsi.insert(v[i]);
    }
    
    int id=1;
    map<int, int> m;
    for(auto e : vsi){
        m[e] = id++;
    }
    
    for(auto &e : v){
        e = m[e];
    }
    
    ll ans =0;
    
    int l=0;
    int k=0;
    for(int r = 0; r<N; r++){
        int e = v[r];
        if(cnt[e]==0) k++;
        cnt[e]++;
        while(k>K){
            int ec = v[l];
            if(cnt[ec]==1) k--;
            cnt[ec]--;
            l++;
        }
        ans += r-l+1;
    }
    cout << ans << endl;
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
