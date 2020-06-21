#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pis pair<ll, string>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

ll sz;
string s;
ll N;
vector<string> p;
ll hashes[102];
ll ph[50010];
ll memo[50200];
ll shift[105];

ll dp(ll i){
    //cout << "#####" << endl;
    //cout << "DP " << i << endl;
    if(memo[i]!= -1) return memo[i];
    if(i >= sz) return memo[i] = 0;
    ll mx = 0;
    for(ll w = 0; w < N; w++){
        //cout << "------------" << endl;
        //cout << "using prefix no. " << w << endl;
        ll firstHash;
        if(i==0) firstHash = 0;
        else firstHash = ph[i-1];
        string pref = p[w];
        ll curHash = hashes[w];
        ll curLen = pref.length();
        if(curLen > sz - i) continue;

        //cout << "hash: " << curHash << endl;

        //preimerjaj hash
        ll lastHash = ph[i+curLen-1];
        firstHash = (firstHash*shift[curLen])%mod;
        ll sHash = (lastHash - firstHash)% mod;
        while(sHash < 0) sHash += mod;
        //cout << "fh: " << firstHash << " | lh: " << lastHash <<" | dif: " << sHash<< endl; 
        if(sHash == curHash){
            //cout << "#USED" << endl;
            mx = max(mx, dp(i+curLen) + curLen);
        }
    }
    //cout << "//////////////" << endl;
    return memo[i] = mx;
}

void PH(){
    ll len = s.length();
    ll cur = 0;
    loop(i, len){
        cur = ((cur*26) + (s[i]-'A')) %mod;
        ph[i] = cur;
        //cout << cur << endl;
    }
    return;
}

ll HASH(string a){
    ll len = a.length();
    ll out = 0;
    for(ll i = 0; i<len; i++){
        out = ((out*26) + (a[i] - 'A')) % mod;
    }
    return out;
}

int main(){
    cin >> N;
    loop(i, N){
        string temp;
        cin >> temp;
        p.pb(temp);
    }
    shift[1] = 26;
    loop(i, 103){
        shift[i+2] = (shift[i+1]*26)%mod;
    }
    //sort(all(p));
    //reverse(all(p));
    loop(i, N){
        hashes[i] = HASH(p[i]);
        //cout << hashes[i] << endl;
    }
    cin >> s;
    sz = s.length();
    PH();
    memset(memo, -1, sizeof memo);
    cout << dp(0) << endl;
}