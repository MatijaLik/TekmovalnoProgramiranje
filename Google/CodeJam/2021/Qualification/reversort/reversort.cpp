/**
 * Author: MatijaL
 * Time: 2021-03-26 19:04:21
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

int eval(vector<int> v){
    int n = v.size();

    int ans = 0;
    FOR(i, 0, n-2){
        //najdi najmanjsega
        int smol = inf;
        int J;
        FOR(j, i, n-1){
            if(v[j] < smol){
                smol = v[j];
                J = j;
            }
        }
        ans += J-i+1;
        reverse(&v[i], &v[J+1]);
    }

    return ans;
}
void solve(){
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    FOR(i, 1, n)v[i-1] = i;

    do{
        if(eval(v) == c) {
            print(v);
            return;
        }
    }while(next_permutation(all(v)));

    cout << "IMPOSSIBLE" << endl;
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    FOR(i, 1, t) {printf("Case #%d: ", i) ;solve();}
}
