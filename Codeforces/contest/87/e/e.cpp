/**
 * Author: MatijaL
 * Time: 2021-09-20 12:47:15
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
struct Tocka{
    ld x, y;
    Tocka(ll _x, ll _y):x(_x), y(_y){}
    friend Tocka operator - (Tocka a, Tocka b){
        return Tocka(a.x-b.y, a.y- b.y);
    }
    friend Tocka operator + (Tocka a, Tocka b){
        return Tocka(a.x+b.x, a.y+b.y);
    }
    Tocka& operator *=(ld k){
        x *= k;
        y *= k;
        return *this;
    }
    bool operator < (Tocka druga){
        if(x != druga.x) return x < druga.x;
        else return y < druga.y;
    }
};

ld vProd(Tocka a, Tocka b){
    return a.x*b.y - b.x*a.y;
}

struct Mnogokotnik{
    vector<Tocka> tocke;
    Mnogokotnik(vector<Tocka> v){
        //najdi najmanjso
        Tocka mn = Tocka(inf, inf);
        int mnId = -1;
        loop(i, v.size()){
            if(v[i] < mn){
                mn = v[i];
                mnId=i;
            }
        }

        FOR(i, mnId, v.size()-1) tocke.pb(v[i]);
        loop(i, mnId) tocke.pb(v[i]);
        tocke.pb(v[mnId]);
    } 
};

Mnogokotnik vsotaMickowskega(Mnogokotnik A, Mnogokotnik B){
    int i=0, j=0;
}

void solve(){

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    while(t--) solve();   
}
