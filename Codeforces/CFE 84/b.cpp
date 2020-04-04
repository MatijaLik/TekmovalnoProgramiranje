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

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        bool taken[N];
        memset(taken, 0, sizeof taken);
        vector<pll> ans;
        loop(n, N){
            ll k;
            cin >> k;
            vector<ll> prop;
            loop(q, k){
                ll temp;
                
                cin >> temp;
                temp--;
                prop.pb(temp);
            }
            bool isGud = 0;
            for(auto p: prop){
                if(taken[p]==0){
                    isGud=1;
                    taken[p]=1;
                    //printf("taking %d\n", p);
                    break;
                }
            }
            if(!isGud){
                ans.pb(mp(n+1, -1));
            }
        }
        //cout << taken[3] << endl;
        if(ans.size()>0){
            ll b = -1;
            for(int p = 0; p < N; p++){
                if(taken[p]==0){
                    //cout << p+1 << endl;
                    b = p+1;
                    break;
                }
            }
            cout << "IMPROVE" << endl;
            cout << ans[0].fs << " " << b << endl;
        }else{
            cout << "OPTIMAL" << endl;
        }
    }
}