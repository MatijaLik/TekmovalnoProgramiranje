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
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl

int main(){
    int t;
    cin >> t;
    loop(q, t){
        string t;
        
        cin >> t;
        if(t.length() <= 2){
            cout << t << endl;
            continue;
        }

        bool same = 1;
        FOR(i, 1, t.length()-1){
            //cout << i << endl;
            if(t[i]!=t[i-1]){
                same = 0;
                break;
            }
        }
        if(same){
            //cout << "same" << endl;
            cout << t << endl;
        }else{
            string s = "";
            bool b = 0;
            loop(i, 2*t.length()){
                if(b){
                    s+= '1';
                    b = 0;
                }else{
                    s += '0';
                    b = 1;
                }
            }
            cout << s << endl;
        }
    }
}