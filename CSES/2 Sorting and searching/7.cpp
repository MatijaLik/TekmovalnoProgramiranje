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
    int x, n;
    cin >> n >> x;


    vector<int> v(n);
    vector<int> og(n);
    loop(i, n) {
        cin >> v[i];
    }

    og = v;
    

    ll p1 = 0;
    ll p2 = n-1;

    sort(all(v));
    int sum = 0;
    while(p1 < p2){
        sum = v[p1] + v[p2];

        if(sum == x){
            
            int a = find(all(og), v[p1]) - og.begin();
            og[a] = -1;
            int b = find(all(og), v[p2]) - og.begin();
            cout << a+1 << " " << b+1 << endl;

            return;
        }else if(sum < x) p1++;
        else p2--;

    }
    cout << "IMPOSSIBLE" << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}