/**
 * Author: MatijaL
 * Time: 2020-11-30 16:46:16
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




void solve(){
    ll N, S;
    cin >> N >> S;
    vector<pll> v(N);
    loop(i, N){
        ll l, r;
        cin >> l >> r;
        v[i] = mp(l, r);
    }    

    sort(all(v));
    ll L = 1;
    ll R = 10e9;
    ll M;
    int it = 0;
    while(L < R){
        M = (L+R)/2;
        M++;

        //printf("Testing %lld %lld -> %lld | ", L, R, M);

        ll cost = 0;
        int error = 0;
        //1 prevec
        //2 premalo
        

        int left = 0;
        int right = 0;

        vector<pll> mid;

        for(auto e : v){
            //disjunktnost
            if(e.sc < M){
                left++;
                cost += e.fs;
            }
            else if(e.fs > M){
                right++;
                cost += e.fs;
            }else{
                //se pokriva
                mid.pb(e);
            }
        }

        if(left > N/2){
            //prevec
            R = M-1;
            //printf("prevec\n");
            continue;
        }
        if(right > N/2){
            //premalo
            L = M+1;
            //printf("premalo\n");
            continue;
        }

        sort(all(mid));
        for(auto e : mid){
            if(left < N/2){
                cost += e.fs;
                left++;
            }else{
                cost += M;
            }
        }

        if(cost > S){
            //prevec
            R = M-1;
            //printf("predrago\n");
        }else{
            //dajmo se probat
            L = M;
            //printf("okej\n");
        }
    }
    //printf("RESULT %lld %lld\n", L, R);
    cout << R << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
