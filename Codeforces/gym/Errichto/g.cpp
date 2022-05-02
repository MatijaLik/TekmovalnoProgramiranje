#include <iostream>
#include <cstring>
#include<bits/stdc++.h>
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
    long long a[13][13];
    Matrix(){
        memset(a, 0, sizeof a);
    }
    Matrix operator *(Matrix other){
        Matrix res = Matrix();
        loop(i, 13){
            loop(k, 13){
                loop(j, 13){
                    res.a[i][k] += a[i][j] * other.a[j][k];
                    res.a[i][k] %= mod;
                }
            }
        }
        return res;
    }
};

void printMatrix(Matrix m, string name){
    cout << name << endl;
    loop(i, 13){
        loop(j, 13){
            cout << m.a[i][j] << "|";
        }
        cout << endl;
    }
}

void solve(){
    ll N, K;
    cin >> N >> K;

    vector<ll> a(N);
    vector<ll> c(N);
    loop(i, N) cin >> a[i];
    loop(i, N) cin >> c[i];

    ll p, q, r;
    cin >> p >> q >> r;

    Matrix base = Matrix();
    //PRIPRAVI BASE

    //top row
    loop(i, N){
        base.a[0][i] = c[i]; 
    }
    base.a[0][10] = p;
    base.a[0][11] = q;
    base.a[0][12] = r;

    //diagonala za N-1 elementov (enega damo stran)
    loop(i, N-1){
        base.a[i+1][i] = 1;
    }

    base.a[10][10] = 1;
    base.a[11][10] = 1; base.a[11][11] = 1;
    base.a[12][10] = 1; base.a[12][11] = 2; base.a[12][12] = 1;

    //printMatrix(base, "BASE");

    Matrix res = Matrix();
    //pripravi res
    loop(i, N) res.a[i][0] = a[N-i-1];
    res.a[10][0] = 1; res.a[11][0] = N; res.a[12][0] = N*N;
    //printMatrix(res, "RES");
    
    if(K < N){
        cout << a[K] << endl;
        return;
    }
    K = K - N + 1;


    while(K){

        if(K%2){
            res = base*res;
        }
        //printMatrix(res, "CALCULATED");

        base = base*base;
        K /= 2;
    }

    ll ans = res.a[0][0];
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}