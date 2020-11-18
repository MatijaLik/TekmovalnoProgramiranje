/**
 * Author: MatijaL
 * Time: 2020-11-17 08:37:15
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

char d;

bool sort1(const string &a, const string &b){
    return a + d < b + d;
}

void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    ll totalLen = 0;
    loop(i, n){
        cin >> v[i];
        totalLen += v[i].length();
    }
    ll len = (2*totalLen)/n;
    cin >> d;
    sort(all(v), sort1);
    //for(auto e : v) cout << e << " ";
    //cout << endl;

    string bad = "";
    loop(i, 11)bad += (char)150;

    bool taken[n];
    memset(taken, 0, sizeof taken);
    loop(i, n){
        if(taken[i]) continue;
        string a = v[i];

        string best = bad;
        int bestId = -1;
        loop(j, n){
            if(i == j or taken[j]) continue;
            string can = v[j];
            if(can.length() + a.length() != len) continue;
            
            best = can;
            bestId = j;
            break;
            
        }
        taken[i] = true;
        taken[bestId] = true;
        cout << a + d + best << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
