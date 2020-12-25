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

void solve(){
    int n, m;
    cin >> n >> m;
    string grid[2*n][2*m];
    loop(i, n){
        string s;
        cin >> s;
        loop(j, m){
            string ns = s.substr(j, 1);
            grid[i][j] = ns;
            grid[i+n][j] = ns;
            grid[i][j+m] = ns;
            grid[i+n][j+m] = ns;
        }
    }

    vector<string> base(n);
    bool first = 1;
    loop(i, n)loop(j, m){
        vector<string> cand(n);
        loop(pn, n){
            string ns = "";
            loop(pm, m){
                ns += grid[i+pn][j+pm];
            }
            cand[pn] = ns;
        }
        //cout << "///////" << endl;
        //for(auto e : cand) cout << e << endl;


        if(first){
            first = 0;
            base = cand;
        }else{
            bool bad = 0;
            //compare
            loop(i, n){
                if(cand[i] < base[i]){
                    break;
                }
                if(cand[i] > base[i]){
                    bad = 1;
                    break;
                }
            }
            if(!bad){
                base = cand;
                //cout << "ide" << endl;
            }
        }
    }

    for(auto e : base) cout << e << endl;





}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}