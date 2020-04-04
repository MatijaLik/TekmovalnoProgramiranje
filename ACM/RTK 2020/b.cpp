#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define debug(x) cout << "# " << x << endl;


ll memo[2000];

ll check(ll i){
    if(memo[i]!=-1) return memo[i];
    printf("%d\n", i);
    fflush(stdout);
    ll temp;
    scanf("%d", &temp);
    memo[i] = temp;
    return temp;
}

int main(){
    ll N;
    while(true){
        N = 0;
        scanf("%d", &N); 
        if(N>1025 or N < 6) return 0;
        FOR(i, 1, N) memo[i] = -1;
        
        //construction
        ll rem = N;
        string s;
        loop(i, N/2) printf("1");
        rem -= N/2;
        while(rem--){
            printf("0");
        }
        printf("\n");
        fflush(stdout);
        

        //poisci
        ll steps = 20;
        ll l = 1;
        ll r = N;
        ll ans = -1;
        while(steps--){
            ll mid = (l+r)/2;
            //printf("l %d, r, %d\n", l, r);
            if(check(mid)==1){
                
                if(l==r){//zacni preiksovati levo polovico
                    r = N/2;
                    l = 1;
                }//go right
                l = mid+1;
            }else{
                //smo na koncu
                if(mid<=1){
                    if(check(N)==1){
                        ans = N;
                        break;
                    }else{// glej desno polovico
                        l = N/2;
                        r = N;
                    }
                }else{
                    if(check(mid-1)==1){
                        ans = mid-1;
                        break;
                    }else{//glej levo
                        r = mid-1;
                    }
                }
            }
        }
        ll out = N/2 - ans;
        if(out < 0) out += N;
        printf("%d %d\n", out, 0);
        fflush(stdout);

    }
}