#include <bits/stdc++.h>
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
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl


ll maxSubSum(vector<ll> v){
    ll msf = -inf;
    ll meh = 0;
    for(auto e : v){
        meh += e;
        if(meh < 0) meh = 0;
        if(msf < meh) msf = meh;
        //printf("%lld %lld\n", e, msf);
    }
    //cout << "----" << endl;
    return msf;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a;
    loop(i, n){
        int temp;
        cin >> temp;
        a.pb(temp);
    }

    ll curScore = 0;
    loop(i, n){
        if(i%2==0) curScore += a[i];
    }
    //printf("current %lld\n", curScore);

    vector<ll> oddGains;
    vector<ll> evenGains;
    vector<ll> gain;

    loop(i, n-1){

        gain.pb(a[i] - a[i+1]);
        if(i%2) evenGains.pb(gain[i]);
        else oddGains.pb(-gain[i]);
    }

    /*
    for(auto i : gain){
        cout << i << " ";
    }
    cout << endl;
    */

    ll best = max(
        curScore,
        max(
            curScore + maxSubSum(oddGains),
            curScore + maxSubSum(evenGains)
        )
    );
    
    cout << best << endl;
    


    return;
}




int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}