#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
#define pui pair<unsigned int, unsigned int>
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


vector<unsigned int> paketi;
unsigned int S, K, P;


map<pui, unsigned int> memo;
set<pui> visited;

unsigned int rollingPresek[10100];

unsigned int dp(unsigned int mask, unsigned int p){
    //printf("dp %d %d\n", mask, p);
    if(visited.count(mp(mask, p)) != 0) return memo[mp(mask, p)];

    visited.insert(mp(mask, p));
    if(mask == 0) return memo[mp(mask, p)] = ((ll)1 << p); // 2 ^ p
    if(p == 0) return memo[mp(mask, p)] = 0;
    
    //preverimo rolling rolling
    loop(i, 20){
        if(mask & ((unsigned int)1 << i) and not(rollingPresek[p] & ((unsigned int)1 << i))){
            //printf("ubila si mi hrcka\n");
            return memo[mp(mask, p)] = 0;
        }
    }


    unsigned int newMask = 0;
    loop(i, 20){
        if(mask & ((ll)1 << i) and not(paketi[p-1] & ((unsigned int)1 << i))){
            newMask |= ((ll)1 << i);
        }
    }
    //printf("mask is %d\n", newMask);

    unsigned int ans;
    ans = (
        dp(newMask, p-1)//uporabi
        + 
        dp(mask, p-1)//ne uporabi
    )%mod;


    //printf("dp %d %d is %d\n", mask, p, ans);

    return memo[mp(mask, p)] = ans;
}


int main(){
    cin >> S >> P >> K;
    rollingPresek[0] = 0;
    loop(i, P){
        unsigned int mask = 0;
        loop(j, K){
            int a;
            cin >> a;
            mask |= ((unsigned int)1 << (a-1));
        }
        paketi.pb(mask);
        rollingPresek[i+1] = mask | rollingPresek[i];
    }


    //pripravi za dp 
    cout << dp((1 << S)-1, P) << endl;

}