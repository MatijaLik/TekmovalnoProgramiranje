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

void solve(int cs){
    int n, k;
    cin >> n >> k;
    vector<ll> v;
    loop(i, n){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }


    int result = 0;

    bool active = false;
    ll prev = -1;
    for(auto e : v){
        //printf("checking %d\n", e);
        if(active){
            //printf("is active, prev is %d\n", prev);
            if(e == prev-1){
                if(e == 1){
                    result++;
                    active = false;
                }
                prev = e;
            }else{
                if(e != k)active = false; 
                prev = e;
            }
        }else{
            if(e == k){
                active = true;
                prev = e;
            }
        }
    }

    printf("Case #%d: %d\n", cs, result);
}

int main(){
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}