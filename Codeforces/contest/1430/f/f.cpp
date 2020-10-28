/**
 * Author: MatijaL
 * Time: 2020-10-11 11:05:02
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

#define INF 1e15
ll N, K;
pair<int, int> intervals[2020];
int a[2020];

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
unordered_map<pll, ll, hash_pair> memo;
int states = 0;
ll dp(ll pos, ll rem){
    states++;
    pll p = mp(pos, rem);
    if(memo[p] != 0) return memo[p];

    if(pos == N) return memo[p] = 0;
    if(rem < 0) return memo[p] = INF;

    //okej poglejmo trenutni interval
    ll l = intervals[pos].fs;
    ll r = intervals[pos].sc;
    ll time = r-l;

    ll cost = 0;
    cost += a[pos];
    
    ll reloads = 0;
    ll carryOn;
    if(rem >= a[pos]){
        reloads = 0;
        carryOn = rem-a[pos];
    }else{
        ll toShoot = a[pos] - rem;

        reloads = toShoot/K;

        //if(toShoot % K != 0) reloads++;
        if(reloads * K != toShoot) reloads++;

        carryOn = K*reloads - toShoot;
    }

    if(reloads > time) return memo[p] = INF;

    ll best = INF;

    bool pi = 0;
    //reloadaj se enkrat prej
    if(pos != N-1){
        if(reloads + 1 <= time or intervals[pos].sc < intervals[pos+1].fs){
            best = min(best, carryOn + dp(pos+1, K));
        }
    }
    best = min(best, dp(pos+1, carryOn));
    
    //printf("DP pos %d | rem %lld | cost %d| carryOn %lld| reloads %d -----> %lld\n", pos, rem, cost, carryOn, reloads, best+cost);
    return memo[p] = best + cost;

}

void solve(){
    cin >> N >> K;
    loop(i, N){
        ll l, r, ai;
        cin >> l >> r >> ai;
        //l = 11*i;
        //r = 11*i+8;
       // ai = rand() % K;
        intervals[i] = mp(l, r);
        a[i] = ai;
    }
    
    ll res = dp(0, K);
    if(res >= INF) cout << -1 << endl;
    else cout << res << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
     solve();   
}
