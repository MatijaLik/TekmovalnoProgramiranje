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
        int n;
        cin >> n;
        vector<int> base;
        vector<int> super;
        loop(i, 2*n){
            super.pb(i+1);
        }
        int ans[2*n];
        loop(i, n){
            int temp;
            cin >> temp;
            super.erase(remove(super.begin(), super.end(), temp), super.end());
            base.pb(temp);
            ans[2*i] = temp;
        }
        bool delet = 0;
        loop(i, n){
            int c = ans[2*i];
            bool found = 0;
            for(auto s : super){
                if(s > c){
                    ans[2*i + 1] = s;
                    super.erase(remove(super.begin(), super.end(), s), super.end());
                    found = 1;
                    break;
                }
            }
            if(!found){
                delet = 1;
                break;
            }
        }
        if(delet) cout << -1 << endl;
        else{
            loop(i, 2*n){
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}