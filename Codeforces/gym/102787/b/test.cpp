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

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "w", stdout);

    cout << "300000 300000" << endl;

    int N = 300000;
    //string
    loop(i, N){
        cout << (char)(rand()%26 + 'a');
    }
    cout << endl;

    loop(i, N-5){
        char c = rand()%26 + 'a';
        int id = rand()%(N+i);
        cout << 2 << " " << c << " " << id << endl;
    }

    //length is
    int len = N+N-5;
    cout << 3 << " " << 1 << " " << len << endl;
    cout << 3 << " " << 1<< " " << 1 << endl;
    cout << 3 << " " << len << " " << len << endl;
    cout << 3 << " " << len/2 << " " << len << endl;
    cout << 3 << " " << len/2 << " " << len << endl;
}