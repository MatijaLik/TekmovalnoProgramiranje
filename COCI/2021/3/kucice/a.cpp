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

vector<Tocka> angleSort(Tocka pivot, vector<Tocka> &v, bool include_colinear = false){
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

const int MOD = 1000000007;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

void solve(){
    int N;
    cin >> N;
    Mnozica m;
    loop(i,N){
        int a, b;
        cin >> a >> b;
        m.tocke.push_back(Tocka(a, b));
    }

    ll ans = 0;
    for(auto P : m.tocke){
        vector<Tocka> sorted = axisSort(P, m.tocke);
        //printf("pivoting at point %d %d\n", P.x, P.y);
        //for(auto e : sorted)printf("%d %d\n", e.x, e.y);
        int k=0;
        int a=0;
        int b=0;
        int pans = binpow(2, N); 
        while((b+1) < sorted.size() && polRavnina(P,sorted[(b+1)])==0) b++;
        while(a < sorted.size()){
            //pojdi do a
            while(orientacija(sorted[a], sorted[(b+1)%sorted.size()], P)==1){
                b++;
                if(b==sorted.size()) b=0;
            }
            if(b>=a) k = b-a+1;
            else k = b+1+sorted.size()-a;
            //cout << a << "/" << b << "->" << k << endl;
            pans = sub(pans, binpow(2, k-1));
            a++;
            
        }
        //prazna mnozica
        pans = sub(pans, 1);
        
        ans = add(ans, pans);
        //cout << pans << endl;
        
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}