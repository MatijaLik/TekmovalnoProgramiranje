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

ll N;

vector<vector<ll>> base{{19,6},{7,20}};
vector<vector<ll>> result{{1,0},{0,1}};


ll multiply(ll a, ll b){return (a*b)%mod;};

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> ans {{0,0},{0,0}};
    loop(i, 2){
        loop(k, 2){
            loop(j, 2){
                ans[i][k] = (ans[i][k] + multiply(A[i][j], B[j][k])) % mod;
            }
        }
    }
    return ans;
};

void solve(){
    cin >> N;

    while(N){
        if(N%2){
            result = multiplyMatrix(base, result);
        }
        base = multiplyMatrix(base, base);
        N /= 2;
    }
    cout << result[0][0] << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}