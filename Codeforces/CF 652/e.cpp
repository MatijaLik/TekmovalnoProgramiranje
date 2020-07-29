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

void solve(){
    int n, m;
    cin >> n >> m;

    //naredi w array
    int supply[n];
    loop(i, n) cin >> supply[i];

    //porihtaj vse osebe
    int demand[m][2];
    loop(i, m) {
        int a;
        cin >> a;
        demand[i][0] = a-1; 
        cin >> a;
        demand[i][1] = a-1;
    }

    //naredi razliko
    int diff[n];
    loop(i, n) diff[i] = supply[i];
    loop(i, m){
        diff[demand[i][0]]--;
        diff[demand[i][1]]--;
    }
    
    //naredi funkcijo jed -> vector<osebe>
    vector<int> jvo[n];
    loop(i, m){
        int a = demand[i][0];
        int b = demand[i][1];

        jvo[a].pb(i);
        jvo[b].pb(i);
    }


    //izbere najjaco hrano
    priority_queue<pll> q;
    loop(i, n){
        q.push(mp(diff[i], i));
    }

    vector<int> ans;
    
    while(ans.size() < m){
        pll ronaldoPeder = q.top();
        ll index = ronaldoPeder.first;

        //poglej ce je diff aktualen
        //ce ni terminiraj program

        //poisci vse, ki hocejo toto jed
        //ustrezno zmanjsaj diff
    }



    for(auto e : ans) cout << e+1 << " ";
    cout << endl;
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}