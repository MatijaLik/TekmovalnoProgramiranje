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
#define debug(x) cout << "# " << x << endl


#define P1 "Ashishgup"
#define P2 "FastestFinger"

void solve(){
    int n;
    cin >> n;

    if(n==1){
        cout << P2 << endl;
        return;
    }


    //if odd
    if(n%2){
        cout << P1 << endl;
        return;
    }


    if(n==2){
        cout << P1 << endl;
        return;
    }

    int cnt = 0;
    while(n%2==0){
        cnt++;
        n /= 2;
    }
    //printf("%d %d\n", n, cnt);


    //n je preostanek
    //ce n ni prastevilo smo zmagali


    if(cnt > 1 and n > 1){
        cout << P1 << endl;
    }
    else if(cnt > 1 and n == 1){
        cout << P2 << endl;
    }else{
        //imamo 2*nekaj

        //ce je nekaj prasevilo zmaga Fastest
        // sicer pa Ashishgup

        int nekaj = n;
        int limit = 100000;

        bool prime = 1;
        FOR(i, 2, min(limit, nekaj-1)){
            if(nekaj % i == 0) {
                prime = 0;
                break;
            }
        }



        if(prime){
            cout << P2 << endl;
        }else{
            cout << P1 << endl;
        }
    }

    


    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}