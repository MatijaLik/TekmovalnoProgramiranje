#include <iostream>
#include <cstring>
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

ll n, m, k;

struct Matrix{
    long long a[100][100];
    Matrix(){
        memset(a, 0, sizeof a);
    }
    Matrix operator *(Matrix other){
        Matrix res = Matrix();
        loop(i, 100){
            loop(k, 100){
                loop(j, 100){
                    res.a[i][k] += a[i][j] * other.a[j][k];
                    res.a[i][k] %= mod;
                }
            }
        }
        return res;
    }
};

void solve(){
    cin >> n >> m >> k;

    Matrix base;

    loop(i, m){
        int x, y;
        cin >> x >> y;
        base.a[--x][--y] = 1;
    }

    Matrix res = Matrix();

    loop(i, 100){
        res.a[i][i] = 1;
    }


    while(k){

        if(k%2){
            res = base*res;
        }


        base = base*base;
        k /= 2;
    }

    //prestej vse;
    ll ans = 0;
    loop(i, n)loop(j, n) if(res.a[i][j]) ans = (ans+res.a[i][j])%mod;

    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}