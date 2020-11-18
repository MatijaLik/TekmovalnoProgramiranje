/**
 * Author: MatijaL
 * Time: 2020-10-22 18:35:13
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

#define limit 1000010

bool isPrime[limit];
bool b[limit];
ll divisor[limit];

void erat(){
    FOR(i, 2, limit-1){
        if(b[i]==0){
            isPrime[i] = true;
            for(ll j = i*i; j < limit; j += i){
                b[j] = 1; 
                divisor[j]=i;
            }
        }
    }
    return;
}

void solve(){
    int cumSum[limit];
    erat();
    int A, B, K;
    cin >> A >> B >> K;
    cumSum[0] = 0;
    int p = 1;

    FOR(i, A, B){
        cumSum[p] = cumSum[p-1];
        
        if(isPrime[i] == true) cumSum[p]++;
        p++;
    }

    int len = B-A+1;
    //FOR(i, 0, 10) cout << cumSum[i] << endl;
    int r = 1;
    int l = 0;

    int best = 0; 
    while(r <= len){
        while(cumSum[r] - cumSum[l] >= K) l++;
        //printf("%d - %d\n", l, r);
        best = max(best, r-l);
        r++;
    }

    if(best == len) cout << -1 << endl;
    else cout << best+1 << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
