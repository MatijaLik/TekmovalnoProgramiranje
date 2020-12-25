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

ll AND(int i, int j){
    cout << "AND " << i << " " << j << endl;
    cout.flush();
    ll ans;
    cin >> ans;
    if(ans == -1) exit(1);
    return ans;
}

ll OR(int i, int j){
    cout << "OR " << i << " " << j << endl;
    cout.flush();
    ll ans;
    cin >> ans;
    if(ans == -1) exit(1);
    return ans;
}

ll XOR(int i, int j){
    cout << "XOR " << i << " " << j << endl;
    cout.flush();
    ll ans;
    cin >> ans;
    if(ans == -1) exit(1);
    return ans;
}


void solve(){
    ll N;
    cin >> N;
    vector<ll> v(N);

    //rekonstruiramo a[1]
    
    ll A = XOR(1, 2);
    ll B = XOR(2, 3);

    ll M = A^B; //XOR 13

    ll R = AND(1, 3);
    ll H = AND(1, 2);
    ll G = AND(2, 3);


    ll pivot = 0;
    loop(i, 32){
        bool m = (1LL<<i) & M;
        bool a = (1LL<<i) & A;
        bool b = (1LL<<i) & B;

        bool r = (1LL<<i) & R;
        bool h = (1LL<<i) & H;
        bool g = (1LL<<i) & G;


        bool res;

        if(m){
            if(a){
                if(g) res = 1;
                else res = 0;
            }else{
                if(h) res = 1;
                else res = 0;
            }
        }else{
            if(a){
                if(r) res = 0;
                else res = 1;
            }else{
                if(r) res = 1;
                else res = 0;
            }
        }
        if(res) pivot += (1LL<<i);
    }
    v[0] = pivot^A;
    v[1] = pivot;
    v[2] = pivot^B;

    FOR(i, 3, N-1){
        ll X = XOR(i, i+1);
        v[i] = X^v[i-1];
    }

    cout << "! ";
    loop(i, N) cout << v[i] << " ";
    cout << endl;
    cout.flush();
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
