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
#define inf 1000000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 1000110


ll memo[limit][10];

vector<ll> vsote;
vector<ll> kStevila; // koncna stevila
set<ll> kss;

ll N, M;
ll ds; //dobrodelno stevilo
ll ks; //kontrolna

ll dp(ll i, ll k){
    if(memo[i][k]!= -1)return memo[i][k];
    if(i >= M){
        if(k == ks)return 0;  
        else return -inf;
    }
    ll top = -10*inf;
    top = max(1+dp(i+1, (k+ds)%10), top); // doniras
    for(ll digit : kStevila){
        top = max(dp(i+1, (k+digit)%10), top);
    }
    
    //printf("dp %d %d is %d\n", i, k, top);
    return memo[i][k] = top;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    loop(i, limit)loop(j, 10) memo[i][j] = -1;


    loop(i, N){
        string s;
        cin >> s;
        ll digit = (ll)s[10]-'0';
        if(i==0) {
            ds = digit;
            kss.insert(ds);
        }else{
            if(kss.count(digit)==0){
                kss.insert(digit);
                kStevila.pb(digit);
            }
        } 
    }
    
    loop(i, M){
        string s;
        ll a;
        cin >> s;
        cin >> a;
        vsote.pb(a);

        ll digit = (ll)s[10]-'0';
        ks += digit;
        ks %= 10;
    }
    //printf("kontrola: %d, dobrodelna %d\n", ks, ds);
    sort(all(vsote));
    reverse(all(vsote));
    ll amnt =  dp(0, 0);
    ll sum = 0;
    loop(i, amnt)sum+=vsote[i];
    cout << sum << endl;
}