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
    vector<int> odd;
    vector<int> even;
    loop(i, 2*n){ 
        int temp;
        cin >> temp;
        if(temp%2) odd.pb(i+1);
        else even.pb(i+1);
    }


    loop(i, n-1){
        if(odd.size() >= 2){
            printf("%d %d\n", odd[0], odd[1]);
            odd.erase(odd.begin());
            odd.erase(odd.begin());
        }else{
            printf("%d %d\n", even[0], even[1]);
            even.erase(even.begin());
            even.erase(even.begin());
        }
    }
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