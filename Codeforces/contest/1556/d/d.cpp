/**
 * Author: MatijaL
 * Time: 2021-08-29 16:35:02
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


int OR(int i,int j){
    i++;j++;
    cout << "or " << i;
    cout << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
}
int AND(int i, int j){
    i++;j++;
    cout << "and " << i;
    cout << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
}


int manj(int i, int j){return i & ~j;}

int n, k;

int _or[20000];
int _and[20000];

void solve(){
    cin >> n >> k;
    vector<int> v;
    
    FOR(i, 0, n-1){
        _or[i] = OR(i, (i+1)%n);
        _and[i] = AND(i, (i+1)%n);
    }
    
    FOR(i, 0, n-1){
        int vse;
        int skorVse;
        FOR(j, 0, n-1){
            vse = vse | _or[j];
            if(j!=i and j != ((i+n-1)%n)) skorVse = skorVse | _or[j];
        }
        int ans = manj(vse, skorVse) | _and[i] | _and[(i+n-1)%n];
        v.pb(ans);
    }
    
    print(v);
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    while(t--) solve();   
}
