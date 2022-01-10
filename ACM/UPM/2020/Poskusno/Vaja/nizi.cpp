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
#define inf 1000000000
#define mod 1000000007


string A, B;

string srt(int id, int L, int R){
    if(L==R){
        if(id) return A.substr(L, 1);
        else return  B.substr(L, 1);
    }
    
    int sz = R-L+1;
    string s[3];
    s[0] = srt(id, L, L + sz/3 -1);
    s[1] = srt(id, L + sz/3, L + 2*sz/3 -1);
    s[2] = srt(id, L + 2*sz/3, R);
    sort(s, s+3);
    return s[0] + s[1] + s[2];
}

void solve(){
    cin >> A >> B;
    if(srt(0, 0, A.size()-1) == srt(1, 0, B.size()-1)) cout << "enaka" << endl;
    else cout << "razlicna" << endl;
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