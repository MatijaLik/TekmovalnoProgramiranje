#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
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
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

int main(){
    int t;
    cin >> t;
    loop(q, t){
        ll a, b, p;
        string s;
        cin >> a >> b >>p;
        cin >> s;
        ll len = s.length();
        reverse(s.begin(), s.end());
        s.erase(s.begin());
        char last = 'h';
        char start = s[0];
        int cnt = 0;
        vector<int> path;
        loop(i, len){
            char cur = s[i];
            if(last == cur){
                cnt++;
            }else{
                path.pb(cnt);
                cnt = 1;
                last = cur;
            }
        }
        //path.pb(cnt);
        path.erase(path.begin());
        /*
        for(auto s : path){
            cout << s << " ";
        }
        cout << endl;*/
        int pos = len;
        for(auto s : path){
            if(start == 'A'){
                start = 'B';
                if(p >= a) {
                    p-=a;
                    pos -= s;
                }
                else break;
            }else{
                start = 'A';
                if(p >= b) {
                    p-=b;
                    pos -= s;
                }
                else break;
            }
        }
        cout << pos << endl;

    }
}