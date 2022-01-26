/**
 * Author: MatijaL
 * Time: 2022-01-22 15:35:03
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


string rot(string a){
    reverse(all(a));
    return a;
}

int solve(){
    int n;
    cin >> n;
    set<string> library; //celi string
    set<string> pseudoLibrary;
    bool ans = 0;
    loop(i, n){
        string s;
        cin >> s;
        if(s.length()==1) ans = 1;
        else if(s.length() == 2){
            if(s[0]==s[1]) ans = 1;
            if(library.count(s)) ans = 1;
            if(pseudoLibrary.count(s)) ans = 1;
            library.insert(rot(s));
        }else{
            if(s[0] == s[2]) ans = 1;
            if(library.count(s.substr(1,2))) ans = 1;
            if(library.count(s)) ans = 1;
            pseudoLibrary.insert(rot(s.substr(0,2)));
            library.insert(rot(s));
        }
    }
    //print(library);
    return ans;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
}
