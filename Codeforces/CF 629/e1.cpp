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

#define nlimit 200010

vector<ll> sosedi[nlimit];
ll parent[nlimit];
ll depth[nlimit];
ll N, M;
ll T;
ll tin[nlimit];
ll tout[nlimit];

void DFS(ll node, ll prev, ll d){
    tin[node] = ++T;
    depth[node] = d;
    parent[node] = prev;
    for(auto sosed : sosedi[node]){
        if(sosed == prev) continue;
        DFS(sosed, node, d+1);
    }
    tout[node] = ++T;
}





int main(){
    cin >> N >> M;
    loop(i, N-1){
        ll a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    DFS(1, 1, 0);


    loop(m, M){
        ll K;
        cin >> K;

        ll md = -1;
        ll last = -1;
        vector<ll> before;
        vector<ll> after;

        loop(k, K){
            ll temp;
            cin >> temp;
            if(depth[temp] > md){
                md = depth[temp];
                last = temp;
            }
            before.pb(temp);
        }
        //cout << last << endl;
        for(auto node : before){
            if(node == last) continue;
            after.pb(parent[node]);
        }

        bool gucci = 1;
        for(auto node : after){
            if (not(tin[node] < tin[last] and tout[last] < tout[node])){
                gucci = 0;
                break;
            }
        }
        if(gucci) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}