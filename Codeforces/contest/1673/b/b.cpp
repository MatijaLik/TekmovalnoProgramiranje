/**
 * Author: MatijaL
 * Time: 2022-04-30 16:42:02
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
    string s;
    cin >> s;
    int n = s.length();
    char f = s[0];
    int sec=-1;
    if(n==1){
        cout << "YES" << endl;
        return;
    }
    
    FOR(i, 1, n-1){
        if(s[i]==f){
            sec = i;
            break;
        }
    }
    
    int m = sec;
    
    //vsak samo enkrat
    if(sec==-1)sec=n;
    set<char> ss;
    FOR(i, 0, sec-1){
        ss.insert(s[i]);
    }
    if(ss.size() != sec){
        cout << "NO" << endl;
        return;
    }
    
    //ni ponovitve
    if(m==-1){
        cout << "YES" << endl;
        return;
    }
    
    //ponavljanje
    string match = s.substr(0, m);
    
    int i = sec;
    while(i+m<n){
        if(s.substr(i, m) != match){
            cout << "NO" << endl;
            return;
        }
        i += m;
    }
    
    if(s.substr(i, n-i) != match.substr(0, n-i)){
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    
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
