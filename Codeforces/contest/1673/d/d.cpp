/**
 * Author: MatijaL
 * Time: 2022-04-30 17:04:57
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

ll b, q, y;
ll b_last;

ll c, r, z;
ll c_last;

bool is_in_b(ll x){
    if(x < b or x > b_last) return false;
    if((x - b)%q == 0) return true;
    return false;
}

/*
bool is_in_c(ll x){
    if(x < c or x > c_last) return false;
    if((x - c)%r == 0) return true;
    return false;
}*/


set<int> div(int a){
    set<int> ans;
    FOR(i, 1, 100000){
        if(a%i==0){
            ans.insert(i);
            ans.insert(a/i);
        }
    }
    return ans;
}


bool DEBUG = false;


ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}

int solve(){
    cin >>b >> q >> y;
    cin >>c>> r >> z;
    
    b_last = b + (y-1)*q;
    c_last = c + (z-1)*r;
    
    //is valid
    if(!is_in_b(c)) return 0;
    if(!is_in_b(c_last)) return 0;
    //q mora deliti r
    if(r % q) return 0;
    
    
    set<int> cd;
    if(q==r){
        cd = div(r);
    }else{
        /*
        int cd1 = (r/q)/__gcd(q, r/q);
        cd = div(cd1);
        cd.insert(r);
        cd.erase(1);
        */
        
        int s = r/q;
        if(lcm(s, q)==r)
            cd.insert(s);
        
        set<int> q_divs = div(q);
        for(auto e : q_divs){
            ll prod = e*1LL*s;
            if(prod <= r and lcm(prod, q) == r){
                cd.insert(e*s);
            }
        }
    }
    
    
    if(DEBUG){
        cout << "cds:" << endl;
        print(cd);
    }
    
    ll ANS = 0;
    
    for(auto e : cd){
        ll lower;
        if(is_in_b(c-r)) lower=c-r+e;
        else{
            if(DEBUG) printf("spodaj neomejen\n");
            return -1;
        }
        
        ll upper;
        if(is_in_b(c_last+r)) upper= c_last+r-e;
        else {
            if(DEBUG) printf("zgoraj neomejen\n");
            return -1;
        }
        
        ll l_m = ((c-lower)/e)+1;
        ll u_m = ((upper-c_last)/e)+1;
        
        if(DEBUG){
            printf("e %d | %d-%d -> %d\n", e, l_m, u_m, l_m*u_m);
        }
        
        ANS += u_m*l_m;
        ANS %= mod;
    }
    
    return ANS%mod;
    
}

int main(){

    //ios::sync_with_stdio(0);
   //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int ans = solve();   
        cout << ans << endl;
    }
}
