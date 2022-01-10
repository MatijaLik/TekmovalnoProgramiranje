#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
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
#define inf 1000000000
#define mod 1000000007

#define limit 10500


ll fastPow(ll a, int pow){
    ll ans = 1;
    ll base = a;
    while(pow > 0){
        if(pow%2) ans *= base;
        base *= base;
        base %= mod;
        ans %= mod;
        pow /= 2;
    }
    return ans;
}
ll inv(ll n){
    return fastPow(n, mod-2);
}
ll fact(ll n){
    ll ans = 1;
    FOR(i, 1, n){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

/*
ll comb[limit][limit];
ll dp(int n, int k){
    if(comb[n][k]!=-1) return comb[n][k];
    if(k == 0) return comb[n][k] = 1;
    if(n == 0) return comb[n][k] = 0;
    return comb[n][k] = (dp(n-1, k) + dp(n-1, k-1))%mod;
}*/

ll C(int n, int k){
    if(k == 0) return 1;
    if(n == 0) return 0;
    if(n < k) return 0;
    ll ans = fact(n);
    ans *= inv(fact(k));
    ans%=mod;
    ans *=  inv(fact(n-k));
    ans%=mod;
    return ans;
}


void solve(){
    int N, L;
    vector<int> R;
    cin >> N >> L;

    ll sum = 0;

    loop(i, N){
        int r;
        cin >> r;
        R.pb(r);
        sum += r;
    }
    
    //loop(i, limit) loop(j, limit) comb[i][j] = -1;    
    //dp(limit-1, limit-1);

    if(N == 1){
        cout << L << endl;
        return;
    }
    
    ll ans = 0;
    FOR(last, 0, N-1){
        ans += fact(N-1)*C(L - (sum-(R[last]-1)) + N, N);
        ans %= mod; 
    }
    
    /*
    ll H = fact(N-2);
    
    ll ans = 0;
    //zberi levi in desni magnet
    FOR(l, 0, N-1){
        FOR(r, 0, N-1){
            if(l==r) continue;
            ll rem = L - (sum - (R[l]-1) - (R[r]-1));
            if(rem < 0) continue;
            ans += (C(rem+N, N) * H)%mod;
            printf("%d - %d | %lld | %lld\n", l+1, r+1, C(rem+N, N), rem);
            ans %= mod;
        }
    }*/
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
