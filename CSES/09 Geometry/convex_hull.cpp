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
typedef long long ld;
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

void solve(){
    int n;
    cin >> n;
    Mnozica m;
    loop(i, n){
        int a, b;
        cin >> a >> b;
        m.tocke.push_back(Tocka(a, b));
    }
    m.convexHull(true);
    cout << m.hull.size() << endl;
    for(auto p : m.hull) p.printPoint();
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}