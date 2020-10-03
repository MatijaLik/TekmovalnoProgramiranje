#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define pdd pair<double, double>
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

const double EPS = 1e-9;

struct Line{
    double x1, x2, y;
    Line(double _x1, double _x2, double _y){
        x1 = _x1;
        x2 = _x2;
        y = _y;
    }
};

ll N;
double optL = 0;
double optR = 0;
double opt;

// dx/dy
vector<pdd> blacklist;
vector<double> fullBlacklist;

vector<Line> lines;

void addPair(int i, int j){
    Line line1 = lines[i];
    Line line2 = lines[j];
    if(line1.y == line2.y) return;
    //naj bo line 1 zgoraj
    if(line2.y > line1.y) swap(line1, line2);
    double left = ((double)(line2.x1 - line1.x2) / ((double) line1.y - line2.y));
    double right = ((double)(line2.x2 - line1.x1) / ((double) line1.y - line2.y));

    //vsebuje v sebi optL ali optR
    //if(contains(optL, left, right)) optL = left;
    //if(contains(optR, left, right)) optR = right;

    blacklist.pb(mp(left, right));
    fullBlacklist.pb(left);
    fullBlacklist.pb(right);
    //blacklistR.pb(right);
    //printf("Comparing %d %d | pushing %f and %f\n", i,  j, left, right);
}

bool contains(double val, pdd e){
    return (e.fs < val and val < e.sc);
}

bool compare1(const pdd &i, const pdd &j)
{
    return i.first > j.first;
}

bool compare2(const pdd &i, const pdd &j)
{
    return i.second < j.second;
}

void findOptimalValues(){
    if(blacklist.size() == 0) return;
    //printf("Left\n");
    sort(all(blacklist), compare1);
    for(auto e : blacklist){
        //printf("%f %f\n", e.fs, e.sc);
        if(contains(optL, e)) optL = e.fs;
    }

    //printf("Right\n");
    sort(all(blacklist), compare2);
    for(auto e : blacklist){
        //printf("%f %f\n", e.fs, e.sc);
        if(contains(optR, e)) optR = e.sc;
    }
}


double project(double slope){
    double minX = 1e18;
    double maxX = -1e18;

    for(auto line : lines){
        double x1 = line.x1 + (line.y * slope);
        double x2 = line.x2 + (line.y * slope);

        minX = min(minX, min(x1, x2));
        maxX = max(maxX, max(x1, x2));
    }
    return maxX - minX;
}

void solve(){
    cin >> N;

    ll tx = -inf;
    ll bx = inf;

    loop(i, N){
        double x1, x2, y;
        cin >> x1 >> x2 >> y;
        lines.pb(Line(x1, x2, y));
        tx = max(tx, (ll)x2);
        bx = min(bx, (ll)x1);
    }

    //naredi blacklist
    loop(i, N)FOR(j,i+1, N-1){
        addPair(i, j);
    }

    findOptimalValues();
    if(optL == optR and optL == 0){
        printf("%.10f\n", project(0));
        return;
    }

    if(N > 100)printf("Optimal are %f %f\n", optL, optR);
    //binary search na intervalu optL -> optR
    double dev1 = project(optL);
    double dev2 = project(optR);
    //cout << min(dev1,dev2) << endl;
    printf("%.10f\n", min(dev1,dev2));
    return;
}   


int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}