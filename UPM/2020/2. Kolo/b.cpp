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


vector<stack<ll>> tiri;

int main(){
    vector<ll> v;
    ll temp;
    while(1){
        cin >> temp;
        v.pb(temp);
        if(cin.peek() == EOF|| cin.peek() == '\n') break;
    }
    //cout << "benis" << endl;
    reverse(all(v));

    ll num = 0;
    for(auto vagon : v){
        bool next = 0;
        //cout << vagon << endl;


        for(auto &s: tiri){
            //printf("candindate %d\n", s.top());
            if(s.top()<vagon){
                s.push(vagon);
                //printf("New top %d\n", s.top());
                next = 1;
                break;
            }
        }
        if(next) continue;
        //cout << "pushed" << endl;
        num++;
        stack<ll> s;
        s.push(vagon);
        tiri.pb(s);

    }
    cout << num << endl;
}