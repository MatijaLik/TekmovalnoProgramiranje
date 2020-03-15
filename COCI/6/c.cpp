#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;
#define limit 1001

ll K;
void positive(){
    ll x, y, z;
    /*
    loop(a, 1001)loop(b, a+1)loop(c, b+1){
        if(-1 +(a+b+c) - (a*b + a*c + b*c) + (a*b*c) == K){
            x = a;
            y = b;
            z = c;
        }
    }*/
    x = K+1;
    y = 2;
    z = 2;
    //cout << x << " " << y << " " << z  << endl;

    cout << 2+x+y+z << " " << x+y +(x*y) + (y*z) << endl;
    FOR(i, 2, x+2) cout << 1 << " " << i  << endl;//vrh
    
    FOR(i, 2, x+2) FOR(j, x+2, x+y+2) cout << i << " " << j  << endl;//vmes zgoraj

    FOR(i, x+2, x+y+2) FOR(j, x+y+2, x+y+z+2) cout << i << " " << j  << endl;//vmes << " " <<odaj

    FOR(i, x+y+2, x+y+z+2) cout << i << " " << x+y+z+2 << endl;//<< " " <<odaj

}

void zero(){
    cout << 3 << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
    cout << 2 << " " << 3 << endl;
}

void negative(){
    K = abs(K);
    ll x, y;
    loop(a, 1001)loop(b, a+1){
        if(a*b - a - b  + 1 == K){
            x = a;
            y = b;
        }
    }
    
    cout << 2+x+y <<  " " << (x+y) + (x*y) << endl;
    FOR(i, 2, x+2) cout << 1 << " " << i << endl; //zgoraj
    FOR(i, 2, x+2)FOR(j, x+2, x+y+2)cout << i << " " << j << endl;// vmes
    FOR(i, x+2, x+y+2) cout << i << " " << x+y+2 << endl;//<< " " <<odaj
}

int main(){
    cin >> K;
    if(K > 0) positive();
    if(K == 0) zero();
    if(K < 0) negative();
    return 0;
}