/**
 * Author: MatijaL
 * Time: 2020-11-14 15:38:24
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

ll R(ll a, ll b){

    if(a < b) return R(b, a);
    if(b == 1) return a;
    return R(a/b, b);
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}



void solve(ll a, ll b){
    //cout << a << " " << b << endl;

    ll g = a;
    ll h = b;


    if(g == h or g == 1){
        cout << g << " " << h << endl;
        return;
    }
    if(h == 2){
        cout << g << " " << 2*g << endl;
        return;
    }
    if(g == h*h){
        cout << g << " " << h*g << endl;
        return;
    }


    /*
    ll aMin = b * ((a/b) + b - 1);
    ll aMax = aMin + b;

    if(a < b){
        aMin = 1;
        aMax = 2*b;
    }

    ll bMin = aMin*b;
    ll bMax = aMax*b + b;
    */

    ll top, bot;
    if(a >= 2*b){
        bot = a;
        top = bot+10*b;
        //cout << bot << " " << top << endl;
        FOR(i, bot, top) FOR(j, i*b + a, i*b + a){
            if(R(i, j) == h and gcd(i, j) == g){
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    else if(b < a and a < 2*b){
        bot = a;
        top = a;

        ll i = a;
        ll j = b*a;
        if(R(i, j) == h and gcd(i, j) == g){
            cout << i << " " << j << endl;
            return;
        }
    }else{
        //a < b
        bot = 1;
        top = 2*b;
        FOR(i, bot, top) FOR(j, i*b + a, i*b + a){
            if(R(i, j) == h and gcd(i, j) == g){
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    //printf("%lld %lld\n", aMin, aMax);
    cout << "bf" << endl;
    FOR(i, 1, 10000) FOR(j, 1, 10000){
        if(R(i, j) == h and gcd(i, j) == g){
            cout << i << " " << j << endl;
            return;
        }
    }
    //cout << "error" << endl;
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
        ll a, b;
        cin >> a >>b;
        solve(a,b);
    }  

    

}
