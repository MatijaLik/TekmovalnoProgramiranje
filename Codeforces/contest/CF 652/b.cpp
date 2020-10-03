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


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    //only ones
    bool same = true;
    FOR(i, 1, n-1){
        char c = s[i];
        if(c != s[i-1]){
            same = false;
            break;
        }
    }

    if(same){
        cout << s << endl;
        return;
    }
    
    string prefix = "";
    int swap = 0;
    loop(i, n){
        char c = s[i];
        if(c == '1'){
            swap = i;
            break;
        }
        prefix += '0';
    }


    string suffix = "";
    loop(i, n){
        char c = s[i];
        if(c == '0'){
            suffix = "";
            if(i != swap-1) suffix = "0";
        }
        else suffix += c;
        //cout << suffix << endl;
    }

    cout << prefix + suffix << endl;
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}