#include <bits/stdc++.h>
using namespace std;
#define pll pair <ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, n, m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define inf 1500000000
#define mod 1000000007
typedef long long ll;
const ll  EPS = 0;
const long double DEPS = 1e-6;
 
map<string, ll> cnt;
map<string, long double> area;
struct Point{
    ll x;
    ll y;
    Point(ll x1, ll y1){
        x = x1;        
        y = y1;
    } 
 
    Point operator - (Point other){
        return Point(x - other.x, y - other.y);
    } 
}; 
ll vProd(Point a, Point b){
    return (a.x * b.y) - (b.x * a.y);
} 
long double len(Point a, Point b){
    long double A2 = abs(a.x-b.x) * abs(a.x-b.x);
    long double B2 = abs(a.y-b.y) * abs(a.y-b.y);
    return sqrt(A2+B2);
} 
struct Triangle{
    string name;
    vector<Point> v;
    Triangle(Point a, Point b, Point c, string s){
        v.pb(a);
        v.pb(b);
        v.pb(c);
        v.pb(a);
        name = s;
 
        //orientacija
        if(vProd(b-a, c-a) < EPS){
            swap(v[1], v[2]);
        } 
 
        getArea();
 
    } 
    void getArea(){
        long double A = len(v[0], v[1]);
        long double B = len(v[1], v[2]);
        long double C = len(v[0], v[2]);
        long double S = (A+B+C)/2;
 
        long double AR = sqrt(S*(S-A)*(S-B)*(S-C));
        AR = abs(AR);
        area[name] = AR;
        
    } 
    void jeNoter(Point p){
        loop(i, 3){
            Point a = v[i];
            Point b = v[i+1];
            if(vProd(b-a, p-a) < EPS) return;
        } 
        cnt[name]++;
        return;
    } 
};
 
 
bool trikotnikSort(const Triangle &ta, const Triangle &tb){

    //RAZMISLEK 1:
    // Ce ima trikotnik tocke na integer koordinatah
    // bo njegova ploscina celo stevilo ali polovica celega stevila
    // npr. (3,0    4,5   9,5)  

    ll a = round(cnt[ta.name]);
    ll b = round(2*area[ta.name]);

    ll c = round(cnt[tb.name]);
    ll d = round(2*area[tb.name]);

    /*
    * tocke1/ploscina1 > tocke2/ploscina2
    * a/b > c/d
    * 
    * kar je ekvivalentno
    * 
    * a*d > b*c
    * samo da se tu izgnemo deljenju
    * 
    */
    if(a*d == b*c) return ta.name < tb.name;
    return a*d > b*c;
} 
 
int N, M;
void solve(){
    cin >> N >> M;
    vector<Point> tocke;
    loop(i, N){
        ll x, y;
        cin >> x >> y;
        Point p = Point(x, y);
        tocke.pb(p);
    } 
 
    vector<Triangle> trikotniki;
    loop(i, M){
        string s;
        ll a, b, c, d, e, f;
        cin >> s;
        cin >> a >> b >> c >> d >> e >> f;
        Point p1 = Point(a, b);
        Point p2 = Point(c, d);
        Point p3 = Point(e, f);
        Triangle t = Triangle(p1, p2, p3, s);
        trikotniki.pb(t);
    } 
    
    for(auto t : trikotniki){
        for(auto tocka : tocke){
            t.jeNoter(tocka);
        } 
    } 
 
    sort(all(trikotniki), trikotnikSort);
    for(const Triangle e : trikotniki){
         cout << e.name << endl;
        //printf("%.15Lf %.15Lf %.15Lf\n", cnt[e.name], area[e.name], cnt[e.name]/area[e.name]);
    }
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}