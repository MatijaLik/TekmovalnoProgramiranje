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

ll solve(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    ll cnt = 0;
    
    int id = 0;

    vector<ll> v;

    int cc = 1;
    char prev = s[0];
    FOR(i, 1, N-1){
        char c = s[i];
        if(c != prev){
            v.pb(cc);
            cc = 1;
            prev = c;
        }else{
            cc++;
        }
        
    }
    v.pb(cc);
    
    int X = v.size();
    int del = 0;
    int av = 0;

    while(true){
        av = max(del, av);
        while(v[av] < 2){
            av++;
            if(av >= X){
                double rem = X - del;
                cnt += ceil(rem/2.0);
                return cnt;
            }
        }
        v[av]--;
        del++;
        cnt++;
    } 
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) cout << solve() << endl;   
}
