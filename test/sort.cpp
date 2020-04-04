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

int main(){
    int a,b,c,x,y,z,d;

    cin >> x >> y >> z >> d;


    int ide[] = {x,y,z,d};

    /*

    285 286 287 288 289

    x   y    z  d   NULL

    */
   sort(ide, ide + 4);

   //reverse(ide, ide + sizeof ide);


    a = ide[3] - ide[1];
    b = ide[3]  - ide[0];
    c = ide[3]  - ide[2];

    
    cout << a <<  " " << b <<  " " << c << endl;
}