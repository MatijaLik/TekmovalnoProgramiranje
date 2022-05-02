/**
 * Author: MatijaL
 * Time: 2022-04-30 16:35:42
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
    int a=0;
    int b=0;
    
    int eval=0;
    for(auto  e : s){
        eval += e-'a'+1;
    }
    
    
    if(s.length()%2==0){
        cout<< "Alice " << eval << endl;
    }else{
        a = min(s[0]-'a'+1, s[s.length()-1]-'a'+1);
        b = eval-a;
        if(a>b){
            cout << "Bob " << a-b << endl;
            
        }else{
            cout << "Alice " << b-a << endl;
        }
    }
    
    
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
