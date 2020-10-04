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


int add(int x, int y, int MOD)
{
	return (x + y) % MOD;
}

int sub(int x, int y, int MOD)
{
	return add(x, MOD - y, MOD);
}

int mul(int x, int y, int MOD)
{
	return (x * 1ll * y) % MOD;
}


void solve(){
    ll N, K, W;
    cin >> N >> K >> W;

    vector<ll> L(N);
    ll al, bl, cl, dl;
    loop(i, K) cin >> L[i];
    cin >> al >> bl >> cl >> dl;
    FOR(i, K+1, N)
        L[i] = add(
            add(mul(al, L[i-2], dl), mul(bl, L[i-1], dl), dl),
            add(cl, 1, dl),
            dl
        );

    vector<ll> H(N);
    ll ah, bh, ch, dh;
    loop(i, K) cin >> H[i];
    cin >> ah >> bh >> ch >> dh;
    FOR(i, K+1, N)
        H[i] = add(
            add(mul(ah, H[i-2], dh), mul(bh, H[i-1], dh), dh),
            add(ch, 1, dh),
            dh
        );

    ll ans = 1;
    ll lastP;


    //calculate the first one
    ll p1 = add(mul(W,2, mod), mul(H[0], 2, mod), mod);
    ans = mul(p1, ans, mod);
    lastP = p1;

    FOR(i, 1, N-1){
        ll curP = lastP;
        
        curP = add(curP, 2*H[i], mod);//1
        curP = add(curP, 2*W, mod);//2


        //poglej ce je sklenjeno
        if(L[i-1] + W >= L[i]){
            curP = sub(curP, 2*min(H[i-1], H[i]), mod); //4
            curP = sub(curP, 2*sub(L[i-1] + W, L[i], mod), mod);
        }
        
        ans = mul(ans, curP, mod);
        
        cout << curP << endl;
        lastP = curP;
    }

    cout << ans << endl;
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    loop(i, t){
        printf("Case #%d:\n", i+1);
        solve();
    }
}