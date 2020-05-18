#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
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

#define N 24

int n;
pair<int, string> memo[1 << N];
pii home;
vector<pii> items;

ll dist(pii a, pii b){
    return (a.fs-b.fs)*(a.fs-b.fs) + (a.sc-b.sc)*(a.sc-b.sc);
}

pair<int, string> dp(ll mask){
    //printf("DP %d\n", mask);
    if(memo[mask] != mp(-1, (string)"")) return memo[mask];
    if(mask == (1 << n)-1)//vsi polni
        return mp(0, "");

    //najdemo prvega praznega
    int firstBit;
    FOR(i, 0, n-1) if(!(mask & (1 << i))) {firstBit = i; break;}

    //probamo z vsemi naslednjimi
    pair<int, string> best = mp(inf, "");
    FOR(secondBit, firstBit, n-1){
        if(!(mask & (1 << secondBit))){//je prazen
            ll cost = dist(home, items[firstBit]) + dist(items[firstBit], items[secondBit]) + dist(items[secondBit], home);
            pair<int, string> result = dp(mask | (1 << firstBit) | (1 << secondBit));

            string s;
            if(firstBit != secondBit) s = to_string(firstBit+1) + " " + to_string(secondBit+1) + " 0 ";
            else s = to_string(firstBit+1) + " 0 ";
            if(result.fs + cost < best.fs) best = mp(result.fs + cost, s + result.sc);
        }
    }
    return memo[mask] = best;
}


int main(){
    int a, b;
    cin >> a >> b;
    home = mp(a, b);
    cin >> n;
    loop(i, 1 << n) memo[i] = mp(-1, "");


    loop(i, n){
        int x, y;
        cin >> x >> y;
        items.pb(mp(x, y));
    }

    cout << dp(0).fs << endl << "0 " << dp(0).sc << endl;
    
}