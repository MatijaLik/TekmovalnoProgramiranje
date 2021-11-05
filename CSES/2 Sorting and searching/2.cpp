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
#define inf 2000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;   

    int res = 0;

    vector<int> people(n);
    vector<int> aps(m);

    loop(i, n)cin >> people[i];
    loop(i, m)cin >> aps[i];

    sort(all(people));
    sort(all(aps));

    int p = 0;

    loop(i, n){
        if(p >= m) break;

        int person = people[i];
        //printf("testing for %d\n", person);

        int cur = aps[p];

        bool abort = false;

        while(cur <= person+k and abs(cur - person) > k){
            p++;
            if(p>=m){abort = true; break;}
            cur = aps[p];
        }

        if(abort) break;
        if(abs(cur - person) <= k){
            p++;
            res++;
        }

        
    }

    cout << res << endl;
}