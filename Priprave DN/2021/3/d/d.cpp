/**
 * Author: MatijaL
 * Time: 2020-11-17 10:04:04
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

bool ascending(pll &a, pll &b){
    return a.sc < b.sc;
}
bool descending(pll &a, pll &b){
    return a.sc > b.sc;
}

void solve(){
    int N, T;
    cin >> N >> T;
    vector<ll> v(N+1);
    FOR(i, 1, N) cin >> v[i];
    vector<pll> queries;
    map<pll, ll> ans;

    loop(i, T){
        ll a, b;
        cin >> a >> b;
        queries.pb(mp(a, b));
    }

    ll bucketSize = sqrt(N);
    ll bucketAmnt = N/bucketSize;
    if(N%bucketSize != 0) bucketAmnt++;
    vector<pll> buckets[bucketAmnt];
    //printf("%lld %lld %lld\n", bucketSize, bucketAmnt);
    for(auto q : queries){
        int id = (q.fs-1)/bucketSize;
        assert(id < bucketAmnt and id >= 0);
        buckets[id].pb(q);
    }   

    //sorting
    loop(i, bucketAmnt){
        if(i % 2 == 0) sort(all(buckets[i]), ascending);
        else sort(all(buckets[i]), descending);
    }

    /*
    //debug
    loop(i, bucketAmnt){
        cout << "#####" << endl;
        for(auto e : buckets[i]) cout << e.fs << " " << e.sc << endl;
    }*/

    ll cum = 0;
    ll cnt[1000002];
    ll L = 0;
    ll R = 0;
    memset(cnt, 0, sizeof cnt);

    loop(i, bucketAmnt){
        for(auto e : buckets[i]){
            int l = e.fs;
            int r = e.sc;

            //adjust R
            while(r < R){
                ll elem = v[R];
                cum -= elem*(2*cnt[elem] - 1);
                cnt[elem]--;
                R--;
            }
            while(R < r){
                ll elem = v[R+1];
                cum += elem*(2*cnt[elem] + 1);
                cnt[elem]++;
                R++;
            }

            //adjust L
            while(l < L){
                ll elem = v[L-1];
                cum += elem*(2*cnt[elem] + 1);
                cnt[elem]++;
                L--;
            }
            while(L < l){
                ll elem = v[L];
                cum -= elem*(2*cnt[elem] - 1);
                cnt[elem]--;
                L++;
            }

            ans[e] = cum;
        }
    }

    for(auto q : queries) cout << ans[q] << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
