#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

int cti(char c){
    return ((int)c - '0');
}

ll flip(string a){
    ll out = 0;
    ll len = a.length();
    for(int i = 0; i < len; i++){
        out += cti(a[i]) * pow(10, i);
    }
    return out;
}

void print(ll s){
    while(s % 10 == 0){
        s /= 10;
        //cout << s << endl;
    }
    ll out = 0;
    //cout << " h" << endl;
    while(s){
        out *= 10;
        out += s%10;
        s /= 10;
    }
    cout << out << endl;
}


int main(){
    string a, b;
    cin >> a >> b;
    ll sum = flip(a) + flip(b);
    //cout << sum << endl;
    print(sum);
    return 0;
}