#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl;


void solve(int cs){
    int N;
    cin >> N;

    bool valid = 1;

    int free[] = {-1, -1};
    vector<pll> q;
    vector<pll> og;


    map<pll, string> m;
    loop(i, N){
        int s, e;
        cin >> s >> e;
        q.pb(mp(s, e));
        og.pb(mp(s, e));
    }

    sort(all(q));
    loop(i, N){
        pll p = q[i];
        int s= p.fs;
        int e =p.sc;

        bool gud = 0;
        loop(i, 2){
            if(free[i] <= s){
                free[i] = e;
                if(i==0) m[p] = "J";
                else m[p] = "C";
                gud = 1;
                break;
            }
        }
        if(!gud) {valid = 0; break;}
    }

    //cout << valid << endl;
    set<pll> visited;
    printf("Case #%d: ", cs);
    if(valid){
        for(pll p: og){
            if(visited.count(p)){
                if(m[p]=="J") cout << "C";
                else cout << "J";
            }else cout << m[p];
            visited.insert(p);
            
        }
        cout << endl;
    } 
    else cout << "IMPOSSIBLE" << endl; 
}


int main(){
    int t;
    cin >> t;
    int i = 1;
    while(t--)solve(i++);
}