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
    bool operator ==(Tocka t){
        return x==t.x&&y==t.y;
    }
    bool operator !=(Tocka t){
        return x!=t.x||y!=t.y;
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
    ld dist(Tocka a){
        return (x-a.x)*(x-a.x) + (y-a.y)*(y-a.y);
    }
};
ld vProd(Tocka a, Tocka b){
    return a.x*b.y - b.x*a.y;
}

ld sProd(Tocka a, Tocka b){
    return a.x*b.x + a.y*b.y;
}

int orientacija(Tocka a, Tocka b, Tocka c){
    ld prod = vProd(b-a, c-a);
    if(prod==0) return 0;
    else if(prod>0) return 1;
    else return -1;
}

int polRavnina(Tocka pivot, Tocka a){
    if(a.y > pivot.y) return 0;
    if(a.y < pivot.y) return 1;
    if(a.x > pivot.x) return 0;
    if(a.x < pivot.x) return 1;
    return 0;
}

vector<Tocka> axisSort(Tocka pivot, vector<Tocka> &v){
    vector<Tocka> sorted;
    for(auto e : v)if(e!=pivot) {sorted.push_back(e);}
    sort(sorted.begin(), sorted.end(), [&pivot](Tocka a, Tocka b){
        bool aSide = polRavnina(pivot,a);
        bool bSide = polRavnina(pivot, b);
        if(aSide != bSide) return aSide<bSide;
        return orientacija(pivot, a, b) > 0;
    });
    return sorted;
}

vector<Tocka> angleSort(Tocka pivot, vector<Tocka> &v, bool include_colinear){
    vector<Tocka> sorted;
    for(auto e : v)if(e!=pivot) {sorted.push_back(e);}
    sort(sorted.begin(), sorted.end(), [&pivot](Tocka a, Tocka b){
        if(orientacija(pivot, a, b)==0){
            return pivot.dist(a)<pivot.dist(b);
        }
        return orientacija(pivot, a, b) == 1;
    });
    if(include_colinear){
        int i = (int)sorted.size()-1;
        while (i >= 0 && orientacija(pivot, sorted[i], sorted.back())==0) i--;
        reverse(sorted.begin()+i+1, sorted.end());
    }
    return sorted;
}



struct Mnozica{
    vector<Tocka> tocke;
    vector<Tocka> hull;
    Mnozica(){}
    Mnozica(vector<Tocka> v): tocke(v){}
    void convexHull(bool include_collinear = false){
        sort(tocke.begin(), tocke.end());
        Tocka start = tocke[0];
        vector<Tocka> sorted = angleSort(start, tocke, include_collinear);
        hull.clear();
        hull.push_back(start);
        for(auto e : sorted){
            while(hull.size() > 1 && orientacija(hull[hull.size()-2], hull[hull.size()-1], e)<0)
                hull.pop_back();
            hull.push_back(e);
        }
    }
};

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
        //O(n)
        for(int i = 0; i < tocke.size() -1; i++){
            if(vProd(tocke[i+1]-tocke[i], t-tocke[i]) < 0) return false;
        }
        return true;
    }

    bool isInFast(Tocka t){
        //O(log n)
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

Mnogokotnik vsotaMinkowskega(Mnogokotnik A, Mnogokotnik B){
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



