/**
 * Author: MatijaL
 * Time: 2020-11-29 14:08:46
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

void solve(){
    int N, K;
    cin >> N >> K;
    vector<ll> v(N);
    loop(i, N) cin >> v[i];
    sort(all(v));

    int pos = 0;
    int neg = 0;
    for(auto e : v) if(e <0) neg++;
    ll posSum = 0;
    for(auto e : v) if(e > 0) posSum += e;

    if(neg <= K){
        cout << posSum << endl;
        return;
    }
    if(K == 0){
        reverse(all(v));
        ll cum = 0;
        ll ans = 0;
        for(auto e : v){
            ans += cum;
            cum += e;
        }
        cout << ans << endl;
        return;
    }



    ll ans = 0;
    //precompute
    reverse(all(v));
    ll cum = 0;
    for(auto e : v){
        if(e < 0) break;
        ans += cum;
        cum += e;
    }

    cout << ans << endl;
    reverse(all(v));

    vector<int> stacks(K, 1);
    int stackP = 0;
    int mainH = 1;

    int p = 0;
    for(auto p = K+1; p < N; p++){
        ll e = v[p];
        if(e >= 0)break;
        printf("allocating %lld\n", e);
        e = abs(e);
        ll oc1;
        oc1 = stacks[stackP]*e;

        ll oc2;
        oc2 = mainH*e - posSum;
        

        printf("%lld %lld\n", oc1, oc2);
        if(oc1 < oc2){
            stackP++;
            stackP %= (K);
            ans -= oc1;
        }else{
            mainH++;
            ans -= oc2;
        }
        
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
