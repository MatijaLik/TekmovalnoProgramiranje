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

#define limit 2000

ll HASH(string a){
    ll len = a.length();
    ll out = 0;
    for(ll i = 0; i<len; i++){
        out = ((out*26) + (a[i] - 'A')) % mod;
    }
    return out;
}

vector<ll> children[limit];
ll parent[limit];


string DFS(ll node){
    ll numOfC = children[node].size();
    if(numOfC == 0) return "0";
    else if(numOfC == 1){
        string cr = DFS(children[node][0]);
        return "1" + cr;
    }else{
        string cr1 = DFS(children[node][0]);
        string cr2 = DFS(children[node][1]);
        return "2" + max(cr1, cr2) + min(cr1, cr2);
    }
}

int main(){
    ll T;
    cin >> T;
    loop(t, T){
        string tree[2];
        loop(f, 2){
            memset(parent, -1, sizeof parent);
            string s;
            cin >> s;
            loop(i, s.length()/4){
                ll start = i*4;
                string a = s.substr(start, 2);
                string b = s.substr(start+2, 2);
                children[HASH(a)].pb(HASH(b));
                parent[HASH(b)] =  HASH(a);
                //cout << HASH(a) << " " << HASH(b) << endl;
            }
            ll cn = HASH(s.substr(0, 2));
            while(parent[cn]!= -1) cn = parent[cn];
            string res = DFS(cn); 
            //cout << cn << endl;
            //cout << res << endl;
            //cout << "-------" << endl;
            for (auto& v : children) {
                v.clear();
            }
            tree[f] = res; 
        }
        if(tree[0] == tree[1]){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }

}