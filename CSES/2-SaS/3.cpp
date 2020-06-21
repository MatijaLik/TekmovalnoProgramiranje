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

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;

    vector<int> v (n);
    loop(i, n) cin >> v[i];
    sort(all(v));

    int p1 = 0;
    int p2 = n-1;

    int res = 0;
    while(p1 <= p2){

        if(p1 == p2){res++; break;}

        int cd1 = v[p1];
        int cd2 = v[p2];

        if(cd1+cd2 <= x) p1++;

        p2--;
        res++;

    }   


    cout << res << endl;


}