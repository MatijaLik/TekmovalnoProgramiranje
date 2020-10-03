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

ll getXFromFX(ll fx, ll nekaj, ll pre){

    ll remaining = fx;

    ll base = 1;
    ll res = 0;

    bool ban = true;

    //prvo sestavimo zadnji del

    //printf("assembly of %lld %lld %lld\n", fx, nekaj, pre);

    if(nekaj){
        res += 10 - pre;
        //cout << res << endl;
        remaining -= 10 - pre;
        //dodatne devetke
        loop(i, nekaj - 1){
            base *= 10;
            res += base*9;
            remaining -= 9;
        }
        base *= 10;
        ban = true;
    }

    //printf("After nines %lld, remaining %lld, base %lld\n", res, remaining, base);
    if(remaining < 0) return -1;
    if(pre == -1) ban = false;//imamo samo x
    
    //naredimo se preostanek
    //kok nam se manjka?
    while(remaining){
        if(remaining >= 9){//damo not kok se da
            if(!ban) {
                res += base*9;
                remaining -= 9;
            }else{
                res += base*8;
                remaining -= 8;
                ban = false;
            }
            
        }else{//lepo pocasi
            res += base*remaining;
            break;
        }

        base *= 10;
    }
    //printf("end result %lld\n", res);

    return res;
}

ll sumOfDigits(ll x){
    ll ans = 0;
    while(x){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

bool verify(ll x, ll k, ll n){
    ll ans = 0;
    FOR(i, 0, k){
        ans += sumOfDigits(x + i);
    }
    if(ans == n) return 1;
    else return 0;
}

void solve(){
    ll N, K;
    cin >> N >> K;

    //iscemo f(x)
    //iteriramo po nekaj (1 ... 17)
    //iteriramo po b (1 .. k)
    if(K == 0){
        cout << getXFromFX(N, 0, -1) << endl;
        return;
    }
    
    vector<ll> answers;

    FOR(nekaj, 0, 17){
        FOR(b, 0, K){
            ll stevec = N - (K*(K+1))/2 + 9*b*nekaj;
            ll imenovalec = K+1;

            
            //ne deli
            if(stevec % imenovalec) continue;

            ll fx = stevec/imenovalec;
            //printf("SOLUTION %lld | nekaj %lld | rem %lld\n", fx, nekaj, K+1-b);

            ll suggestion = getXFromFX(fx, nekaj, K+1-b);
            //cout << suggestion << endl;
            if(suggestion != -1 and verify(suggestion, K, N)){
                //preveri rezultat
                answers.pb(suggestion);
            }
            

            //cout << getXFromFX(fx, nekaj, K+1-b) << endl;
        }
    }


    

    if(answers.size() == 0){
        cout << -1 << endl;
    }else{
        ll best = LLONG_MAX;
        for(ll a : answers){
            best = min(best, a);
        }
        cout << best << endl;
    }
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