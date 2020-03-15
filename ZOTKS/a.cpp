#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
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
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


map<ll, ll> cnt;
vector<ll> podnizi;
set<ll> podniziS;


int main(){
    string s;
    cin >> s;
    ll N;
    cin >> N;
    ll M = s.length();
    //zacetni hash
    ll hash = 0;
    FOR(i, 0, N){
        hash *= 2;
        char c = s[i];
        if(c == 'B'){
            hash += 1;
        }
    }

    cnt[hash]++;
    podnizi.pb(hash);
    podniziS.insert(hash);
    //cout << hash << endl;
    FOR(i, N, M){
        //zadnjega stran
        hash = hash%(1<<N-1);
        hash *= 2;
        char c = s[i];
        if(c == 'B'){
            hash += 1;
        }
        cnt[hash]++;
        if(podniziS.count(hash)==0)podnizi.pb(hash);
        //cout << hash << endl;
    }

    sort(all(podnizi));
    ll max = 0;
    int best;
    for(auto niz : podnizi){
        if(cnt[niz] > max){
            max = cnt[niz];
            best = niz;
            //debug(niz);
        }
    }
    string ans = "";
    loop(i, N){
        bool c = best&(1 << i);
        if(c) ans = "B" + ans;
        else ans = "A" + ans;
    }
    cout << ans << endl;
    return 0;
}