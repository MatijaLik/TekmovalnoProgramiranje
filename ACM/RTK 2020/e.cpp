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

#define nlimit 100010


ll parent[nlimit];
vector<ll> children[nlimit];
vector<ll> sosedi[nlimit];

ll worth[nlimit];
ll profit[nlimit];
map<pll, ll> cost;

ll DFS(ll node, ll prev){
    ll price = worth[node];
    price -= cost[mp(node, prev)];
    for(auto sosed : sosedi[node]){
        if(sosed == prev) continue;
        parent[sosed] = node;
        children[node].pb(sosed);
        price += DFS(sosed, node);
    }
    profit[node] = price;
    return price;


}


int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;

        memset(parent, 0, sizeof parent);
        memset(children, 0, sizeof children);
        memset(sosedi, 0, sizeof sosedi);

        memset(worth, 0, sizeof worth);
        memset(profit, 0, sizeof profit);
       
        

        
        FOR(i,1, N){
            cin >> worth[i];
        }
        
        
        loop(i, N-1){
            ll a, b, c;
            cin >> a >> b >> c;
            sosedi[a].pb(b);
            sosedi[b].pb(a);
            cost[mp(a, b)] = c;
            cost[mp(b, a)] = c;
        }

        parent[1] = 1;
        DFS(1, 1);


        priority_queue<pair<pll, ll>> q;
        priority_queue<pair<pll, ll>> awaiting;
        ll keys = worth[1];
        for(auto child: children[1]){
            q.push(mp(mp(-cost[mp(1, child)],worth[child]), child));
        }
        int error = 0;
        ll visited = 1;
        while(!q.empty() or !awaiting.empty()){
            if(!q.empty() and keys < 0){
                error = 1;
                break;
            }
            if(q.empty()) break;
            pair<pll, ll> p = q.top();
            q.pop();

            //visit node
            ll node = p.sc;
            visited++;
            printf("visiting %d\n", node);
            
            
            keys -= cost[mp(node, parent[node])];
            if(keys < 0){
                error = 1;
                break;
            }
            keys += worth[node];
            for(auto child: children[node]){
                q.push(mp(mp(-cost[mp(node, child)],worth[child]), child));
                printf("pushing %d\n", child);
            }
            cout << keys << endl;
            
        }
        if(error or visited!= N) cout << "da" << endl;
        else cout << "ne" << endl;

    }

}