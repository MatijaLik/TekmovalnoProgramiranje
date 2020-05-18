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

#define limit 100010


const ll allLimit  = 1e8 + 10;

const double EPS = 1e-9;

bool perfect[allLimit]

void solve(int cs){
    int n;
    cin >> n;


    int result = 0;

    ll arr[limit];
    ll rs[limit];
    rs[0] = 0;
    FOR(i, 1, n){
        cin >> arr[i];
        rs[i] = rs[i-1] + arr[i];
    }

    FOR(i, 1, n){
        FOR(j, i, n){
            double sum = rs[j] - rs[i-1];
            double sr = sqrt(sum);
            if(sr - (floor(sr)) < EPS){
                result++;
                //printf("%d %d\n", i, j);
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