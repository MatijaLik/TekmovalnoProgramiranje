#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pint pair<long long, long long>
#define pli pair<long long, int>
#define vi vector <int>
#define mii map<int, int>
#define si set<int>
#define loop(i, n) for(int i = 0; i < n; i++)
#define FOR(i,n,m) for(int i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 9999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define limit 30

ll nums[100010];
ll N;
map<string, ll> memo;
set<string> found;

ll stl(string s){
    ll out = 0;
    int ex = limit-1;
    for(auto c : s){
        if(c=='1'){
            out += (1 << ex);
        }
        ex--;
    }
    return out;
}

ll dp(string pref, ll start){
    //cout << "DP " << pref <<  " " << start << endl;

    //memoizacija
    if(found.count(pref) != 0) return memo[pref];

    found.insert(pref);

    //robni primer
    if(pref.length()==limit) return memo[pref] = 0;


    ll area = stl(pref);
    ll dif = (1 << (limit - pref.length()));
    ll check = (1 << (limit - pref.length()-1));
    bool zp = 0;
    bool op = 0;
    
    ll point = start;
    ll nextStart;
    while(point < N){
        ll num = nums[point];
        //edge case
        if(num >= area+dif) break;

        if(num & check){
            if(op==0) nextStart = point;
            op = 1;
        } 
        else zp = 1;
        point++;
    }
    if(zp & op){
        // cost = check
        return memo[pref] = check + min(dp(pref+'0', start), dp(pref+'1', nextStart));
    }else{
        if(zp) return memo[pref] = dp(pref+'0', start);
        else return memo[pref] = dp(pref + '1', nextStart);
    }
}


int main(){

    //sortiraj
    cin >> N;
    vector<ll> v;
    loop(i, N){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(all(v));
    loop(i, N){
        nums[i] = v[i];
    }
    cout << dp("", 0) << endl;
    return 0;
}