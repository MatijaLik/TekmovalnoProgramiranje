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
    Tocka(){x=0;y=0;}
    friend Tocka operator - (Tocka a, Tocka b){
        return Tocka(a.x-b.x, a.y- b.y);
    }
    friend Tocka operator + (Tocka a, Tocka b){
        return Tocka(a.x+b.x, a.y+b.y);
    }
    Tocka& operator *=(ld k){
        x *= k;
        y *= k;
        return *this;
    }
    Tocka& operator -(){
        x = -x;
        y = -y;
        return *this;
    }
    bool operator < (Tocka druga){
        if(x != druga.x) return x < druga.x;
        else return y < druga.y;
    }
    void printPoint(){
        cout << x << " " << y << endl;
    }
    
};

ld vProd(Tocka a, Tocka b){
    return a.x*b.y - b.x*a.y;
}

ld sProd(Tocka a, Tocka b){
    return a.x*b.x + a.y*b.y;
}

struct Mnogokotnik{
    vector<Tocka> tocke;
    int sz;
    Tocka origin;
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
        sz = tocke.size()-1;
        origin = tocke[0];
    } 

    Mnogokotnik(){

    }

    bool isIn(Tocka t){
        for(int i = 0; i < tocke.size() -1; i++){
            if(vProd(tocke[i+1]-tocke[i], t-tocke[i]) < 0) return false;
        }
        return true;
    }

    bool isInFast(Tocka t){
        Tocka firstSide = tocke[1]- origin;
        Tocka lastSide = tocke[sz-1] - origin;
        Tocka P = t - origin; //prestavimo izhodisce v oglisce lika

        //je zunaj krakov kota v ogliscu
        if(vProd(firstSide, P) < 0 || vProd(lastSide, P) > 0) return false;

        //lezi na krakih
        if(vProd(firstSide, P) == 0){
            if(sProd(P - firstSide, firstSide) > 0) return false;
            else return true;
        }
        if(vProd(lastSide, P) == 0){
            if(sProd(P - lastSide, lastSide) > 0) return false;
            else return true;
        }

        //binsearch zadnja tocka Q, kjer je P x Q > 0
        int l = 1;
        int r = sz;
        int m;
        while(l != r){
            m = (l+r)/2;
            Tocka diag = tocke[m] - origin;
            if(vProd(P, diag) >= 0) r = m;
            else l = m+1;
        }
        m = l;
        //lezi na diagonali
        Tocka diag = tocke[m] - origin;
        if(vProd(P, diag) == 0){
            if(sProd(P - diag, diag) > 0) return false;
            return true;
        }

        if(vProd(tocke[m] - tocke[m-1], P - (tocke[m]-origin)) < 0) return false;
        return true;
    }

    void printPoints(){
        cout << "////" << endl;
        for(int i = 0; i<tocke.size()-1; i++) cout << tocke[i].x << " " << tocke[i].y << endl;
        cout << "////" << endl;
    }
};

Mnogokotnik vsotaMickowskega(Mnogokotnik A, Mnogokotnik B){
    int i=0, j=0;
    Mnogokotnik vsota;
    while(i < A.tocke.size() && j < B.tocke.size()){
        vsota.tocke.pb(A.tocke[i] + B.tocke[j]);
        Tocka P = A.tocke[(i%(A.tocke.size()-1)) + 1] - A.tocke[(i%(A.tocke.size()-1))];
        Tocka Q = B.tocke[(j%(B.tocke.size()-1)) + 1] - B.tocke[(j%(B.tocke.size()-1))];
        ll prod = vProd(P, Q);
        if(prod >= 0) i++;
        if(prod <= 0) j++;
    }
    vsota.origin = vsota.tocke[0];
    vsota.sz = vsota.tocke.size()-1;
    return vsota;
}

void solve(){
    vector<Mnogokotnik> mesta;
    loop(i, 3){
        int n;
        cin >> n;
        vector<Tocka> temp;
        loop(j, n){
            int x, y;
            cin >>x >>y;
            temp.pb(Tocka(x, y));
        }
        mesta.pb(Mnogokotnik(temp));
    }    

    Mnogokotnik O = vsotaMickowskega(mesta[0], vsotaMickowskega(mesta[1], mesta[2]));
    //O.printPoints();

    int m;
    cin >> m;
    loop(i, m){
        int x, y;
        cin >> x >> y;
        x *= 3;y*=3;
        if(O.isInFast(Tocka(x, y))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    while(t--) solve();   
}
