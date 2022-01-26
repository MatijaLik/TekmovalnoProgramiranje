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

int H, W, a1, b1, c1, a2, b2, c2, t;
int x=1, y=1;
ll cas=0;
void move(){

    int tRight;
    if(x == W) tRight = inf;
    else if(cas < a1) tRight = a1-cas;
    else tRight = (cas-a1) % (b1+c1) < b1 ? 0 : b1+c1 - (cas-a1)%(b1+c1);

    int tDown;
    if(y == H) tDown = inf;
    else if(cas < a2) tDown = a2 - cas;
    else tDown = (cas-a2) % (b2+c2) < b2 ? 0 : b2+c2 - (cas-a2)%(b2+c2);

    if(tDown < tRight){
        y++;
        cas += t + tDown;
    }
    else{
        x++;
        cas += t + tRight;
    }
}

void solve(){
    cin >> H >> W >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> t;
    while(x < W or y < H){
        move();
        //printf("%lld| %d %d\n", cas, x, y);
    } 
        
    cout << cas << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}