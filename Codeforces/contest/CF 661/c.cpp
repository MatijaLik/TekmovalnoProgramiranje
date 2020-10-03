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
#define inf 1000000100
#define mod 1000000007

void solve(){
    int n;
    cin >> n;
    vector<ll> w(n);
    loop(i, n) cin >> w[i];

    sort(all(w));

    set<ll> amnt[n];
    vector<ll> sums;

    loop(i, n){
        ll w1 = w[i];
        ll prev = -inf;
        FOR(j, i+1, n-1){
            ll w2 = w[j];

            if(amnt[i].count(w1 + w2)) continue;
            if(amnt[j].count(w1 + w2)) continue;

            amnt[i].insert(w1 + w2);
            amnt[j].insert(w1 + w2);

            sums.pb(w1+w2);
            //printf("Pushing %lld\n", w1+w2);
        }
    }

    ll best = 0;
    for(auto e : sums){
        int cnt = 0;
        loop(i, n){
            if(amnt[i].count(e)) cnt++;
        }

        best = max(best, (ll)cnt);
    }
        
    cout << best/2 << endl;
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();    
}