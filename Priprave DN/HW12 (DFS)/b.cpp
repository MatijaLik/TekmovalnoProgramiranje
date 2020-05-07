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

#define nlimit 100100


int N, M;
int checkPointPrices[nlimit];

vector<int> sosedi[nlimit];

int lowlink[nlimit];
int dfsNum[nlimit];
int component[nlimit];
int curComp = 1;


vector<int> groups[nlimit];
stack<int> s;
int cas = 1;
void dfs(int node){
    //printf("dfs %d\n", node);
    s.push(node);
    lowlink[node] = cas;
    dfsNum[node] = cas++;
    for(auto sosed : sosedi[node]){
        if(dfsNum[sosed] == 0){//neobiskano
            dfs(sosed);
            lowlink[node] = min(lowlink[node], lowlink[sosed]);
        }
        if(dfsNum[sosed] != -1){
            lowlink[node] = min(lowlink[node], dfsNum[sosed]);
        }
    }
    if(lowlink[node] == dfsNum[node]){
        //printf("clearing node %d\n", node);
        int popped = -1;
        while(1){
            popped = s.top();
            s.pop();
            dfsNum[popped] = -1;
            component[popped] = curComp;
            groups[curComp].pb(popped);
            //printf("popped %d\n", popped);
            if(popped == node)break;
        }
        curComp++;
    }
    
}


int main(){
    cin >> N;
    loop(i, N) cin >> checkPointPrices[i+1];
    cin >> M;
    loop(i, M){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
    }

    //nastavi arraye
    loop(i, nlimit){
        lowlink[i] = 0;
        dfsNum[i] = 0;
        component[i] = -1;
    }

    FOR(i, 1, N){
        if(dfsNum[i]!=-1) dfs(i);
    }




    multiset<int> prices[nlimit];
    ll total = 0;
    ll combinations = 1;

    FOR(i, 1, curComp-1){
        ll mini = inf;
        //cout << "component " << i << endl;
        for(auto benis : groups[i]){
            //cout << benis << " ";
            ll cost = checkPointPrices[benis];
            prices[i].insert(cost);
            mini = min(mini, (ll)cost);
        }
        //cout << endl;
        total += mini;
        combinations = (combinations*prices[i].count(mini))%mod;
    }
    cout << total << " " << combinations << endl;
}