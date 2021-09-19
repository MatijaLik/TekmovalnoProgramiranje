/**
 * Author: MatijaL
 * Time: 2021-05-27 18:15:24
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


#define DEBUG 0
int N, H;
vector<ll> S(200000);
void subtaskH(){
    sort(all(S));
    ll med = S[N/2];
    ll cost = 0;
    for(auto e : S) cost += abs(med - e);
    cout << cost << endl;
} 

ll subtask3Eval(ll s0){

    map<pair<ll, ll>, ll> m; //<n, s_n> ----> cost

    m[mp(0, s0)] = abs(S[0] - s0);

    ll top = s0;
    ll bot = s0;

    FOR(n, 1, N-1){
        FOR(sn, max(bot-H, 0LL), top+H){
            ll mini = inf*1LL*inf;
            FOR(sPrev, bot, top){
                if(abs(sn-sPrev) <= H)
                mini = min(mini, m[mp(n-1, sPrev)] + abs(sn - S[n]));
            }
            m[mp(n, sn)] = mini;

            if(DEBUG) printf("n %lld sn %lld ->>> %lld\n", n, sn, mini);
        }

        top += H;
        bot -= H;
        bot = max(bot, 0LL);
    }

    ll mini = inf*1LL*inf;
    FOR(i, bot, top) mini = min(mini, m[mp(N-1, i)]);
    if(DEBUG)printf("%lld ----> %lld\n", s0, mini);
    return mini;
}

void subtask3(){
    ll l = 0;
    ll r = inf;
    ll m;
    while(l + 1 < r){
        //printf("%lld %lld\n", l, r);
        m = (l+r)/2;
        ll e1 = subtask3Eval(m);
        ll e2 = subtask3Eval(m+1);
        if(e1 < e2) r = m;
        else l = m;
    }
    //printf("%lld %lld\n", l, r);
    cout << min(subtask3Eval(l), subtask3Eval(r)) << endl;
}

void solve(){
   
    cin >> N >> H;
    
    ll maxS = 0;
    loop(i, N) {
        ll t;
        cin >> t;
        maxS = max(maxS, t);
        S[i] = t;
    }
    S.resize(N);

    if(H == 0){
        subtaskH();
        return;
    }

    if(maxS > 400){
        subtask3();
        return;
    }
    


    ll dp[N][maxS+1];
    FOR(i, 0, maxS){
        dp[0][i] = abs(S[0] - i);
    }

    FOR(n, 1, N-1){
        FOR(s, 0, maxS){
            ll mini = inf*1LL*inf;
            FOR(sPrev, 0, maxS){
                if(abs(s-sPrev) <= H)
                mini = min(mini, abs(S[n]-s) + dp[n-1][sPrev]);
            }

            dp[n][s] = mini;

            //if(DEBUG)printf("dp %d %d --> %lld\n", n, s, dp[])
        }
    }

    ll mini = inf*1LL*inf;
    FOR(s, 0, maxS) mini = min(mini, dp[N-1][s]);
    cout << mini << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
