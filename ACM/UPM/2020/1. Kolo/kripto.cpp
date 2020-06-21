#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
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
#define debug(x) cout << "# " << x << endl


#define nlimit 70000
#define klimit 11

ll N, K;
ld S;


ld best[nlimit];
pdd bbk[nlimit][11];


int main(){
    memset(bbk, 0, sizeof bbk);
    cin >> N >> K >> S;
    loop(q, K){
        string s;
        cin >> s;
        bool begin = false;
        double prev = 1;
        int iol = -1; //index of last
        loop(i, N){
            ld value;
            cin >> value;
            if(value == -1){
                continue;
            }
            if(!begin){
                begin = true;
                iol = i;
                prev = value;
                continue; 
            }

            ld ratio = value/prev;
            bbk[i][q] = mp(ratio, i-iol);
            iol = i;
            prev = value;
        }
    }

    best[0] = S;
    FOR(i,1, N-1){
        ld optimal = best[i-1];
        loop(k, K){
            ld ratio = bbk[i][k].fs;
            int leap = (int)bbk[i][k].sc;
            optimal = max(optimal, ratio*best[i-leap]);
        }
        best[i] = optimal; 
    }
    

    cout << best[N-1] << endl;
}