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
    while(t--){
        int n;
        cin >> n;

        vector<int> v(n);

        loop(i, n)cin >> v[i];

        sort(all(v));

        int odd = 0;
        int even = 0;

        for(auto e : v){
            if(e % 2 == 0) even++;
            else odd++;
        }


        //prvic
        if(odd%2 == 0){
            cout << "YES" << endl;
            continue;
        }

        int minDif = inf;
        int prev = 0;
        loop(i, n){
            if(i!= 0){
                if(v[i] - prev == 0) continue;
                minDif = min(minDif, v[i]-prev);
            }
            prev = v[i];
        }

        if(minDif == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}