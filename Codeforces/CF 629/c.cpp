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
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;

        string a;
        string b;

        bool det = 0;
        for(auto c : s){
            if(c == '2'){
                if(det){
                    a += '0';
                    b += '2';
                }else{
                    a += '1';
                    b += '1';
                }

            }else if(c == '1'){
                if(det){
                    a += '0';
                    b += '1';
                }else{
                    a += '1';
                    b += '0';
                    det = 1;
                }
                
            }else if(c == '0'){
                a += '0';
                b += '0';
            }
        }
        cout << a << endl;
        cout << b << endl;


    }
}