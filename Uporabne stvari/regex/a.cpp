/**
 * Author: MatijaL
 * Time: 2021-10-14 12:37:27
**/

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
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;

int main(){
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i<n; i++){
        char faks[265];
        int a;
        scanf("%[^0123456789] %d \n", faks, &a);
        string faks_string = string(faks);
        faks_string.pop_back();
    }
    int m;
    scanf("%d\n", &m);
    for(int i = 0; i<m; i++){
        char ime[265];
        char faks[265];
        int a;
        scanf("%[^0123456789] %d %[^\n]\n", ime, &a, faks);
        string faks_string = string(faks);
        string ime_string = string(ime);
    }
}
