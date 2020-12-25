/**
 * Author: MatijaL
 * Time: 2020-12-12 15:31:04
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

set<string> A;
set<string> B;

map<string, bool> memo;
set<string> visited;

bool dp(bool player, string pref){
    if(visited.count(pref)) return memo[pref];
    visited.insert(pref);


    //cout << "DP " << pref << endl;

    int len = pref.length();

    //na voljo je vse med pref@ in pref~
    if(player == 0){
        auto t1 = A.lower_bound(pref + "@");
        auto t2 = A.lower_bound(pref + "~");
        if(t1 == t2) return memo[pref] = 0;

        while(t1 != t2){
            string nPref = (*t1).substr(0, len+1);
            if(dp(1, nPref)) return memo[pref] = 1;
            t1++;
        }
        return memo[pref] = 0;
    }else{
        auto t1 = B.lower_bound(pref + "@");
        auto t2 = B.lower_bound(pref + "~");
        if(t1 == t2) return memo[pref] = 1;

        while(t1 != t2){
            string nPref = (*t1).substr(0, len+1);
            if(!dp(0, nPref)) return memo[pref] = 0;
            t1++;
        }
        return memo[pref] = 1;
    }
}


void solve(){
    int N, M;
    cin >> N;
    loop(i, N){
        string temp;
        cin >> temp;
        A.insert(temp);
    }

    cin >> M;
    
    loop(i, M){
        string temp;
        cin >> temp;
        B.insert(temp);
    }

    bool res = dp(0, "");
    if(res) cout <<"Nina" << endl;
    else cout << "Emilija" << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
