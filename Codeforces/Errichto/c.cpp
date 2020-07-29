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
#define inf 1000000000
#define mod 1000000007

struct Matrix{
    long long a[2][2];
    Matrix operator *(Matrix other){
        Matrix res = {{{0,0},{0,0}}};
        loop(i, 2){
            loop(k, 2){
                loop(j, 2){
                    res.a[i][k] += a[i][j] * other.a[j][k];
                    res.a[i][k] %= mod;
                }
            }
        }
        return res;
    }
};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll N;
    cin >> N;

    if(N == 0){
        cout << 0 << endl;
        return 0 ;
    }

    N--;

    Matrix base {{{1, 1},{1, 0}}};
    Matrix result {{{1,0}, {0,1}}};

    while(N){
        if(N%2){
            result = result*base;
        }
        base = base*base;
        N /= 2;
    }
    cout << result.a[0][0] << endl;
}