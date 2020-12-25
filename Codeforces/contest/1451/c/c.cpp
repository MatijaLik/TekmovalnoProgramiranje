/**
 * Author: MatijaL
 * Time: 2020-11-21 15:35:02
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

bool solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(26, 0);
    vector<int> b(26, 0);

    string sa, sb;
    cin >> sa >> sb;
    for(auto e : sa) a[(int)(e - 'a')]++;
    for(auto e : sb) b[(int)(e - 'a')]++;

    int carry = 0;
    loop(i, 26){
        carry += a[i];
        carry -= b[i];
        if(carry < 0) return false;

        //daj naprej
        if(carry % k) return false;
    }
    if(carry) return false;
    return true;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "Yes" << endl;
        else cout << "No" << endl;   
    }
}
