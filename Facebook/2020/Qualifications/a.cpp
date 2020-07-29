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

vector<int> sosedi[52];
set<int> visited[52];
    
void dfs(int start, int node){

    if(visited[start].count(node)) return;

    visited[start].insert(node);

    for(auto e : sosedi[node]){
        dfs(start, e);
    }
    return;
}


void solve(){

    loop(i, 52){
        sosedi[i].clear();
        visited[i].clear();
    }
    int n;
    cin >> n;

    string in;
    string out;
    cin >> in >> out;
    
    loop(i, n){
        //poglej za nazaj
        if(i != 0){
            if(out[i] == 'Y' and in[i-1] == 'Y') sosedi[i].pb(i-1);
        }

        //poglej za naprej
        if(i != n-1){
            if(out[i] == 'Y' and in[i+1] == 'Y') sosedi[i].pb(i+1); 
        }
    }
    

    loop(i, n){
        dfs(i, i);
        loop(j, n){
            if(visited[i].count(j)) cout << "Y";
            else cout << "N";
        }
        cout << endl;
    }

}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    loop(i, t){
        printf("Case #%d:\n", i+1);
        solve();
    }
}