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
#define inf 1000040000
#define mod 1000000007


struct Line{
    int x1, y1, x2, y2;

    bool const operator <(const Line &other)const{
        if(x1 != other.x1) return x1 < other.x1;
        else return min(y1, y2) < min(other.y1, other.y2);
    }
};


void solve(){
    int N;
    cin >> N;
    vector<Line> lines;
    loop(i, N){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lines.pb(Line{a, b, c, d});
    }

    sort(all(lines));
    loop(i, N-1){
        Line line1 = lines[i];
        Line line2 = lines[i+1];
        printf("%d %d %d %d\n",
                
                line1.x1,
max(line1.y1, line1.y2),

                line2.x1,
                min(line2.y1, line2.y2));
    }
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
