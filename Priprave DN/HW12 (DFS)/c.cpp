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

#define nlimit 300100

ll N, M;

vector<int> sosedi[nlimit];

int lowlink[nlimit];//najmanjsi index, ki je neposedno dostopen iz poljubnega vozlisca poddrevesa
int dfsNum[nlimit];//vrstna stevilka v dfs
int parent[nlimit];//stars
vector<int> children[nlimit];

set<pll> bridges;//mostovi
int bridgeAmountOne[nlimit];//stevilo mostov v poddrevesu
int bridgeAmountTwo[nlimit];
int cas = 1;

void dfs(int node){
    //printf("dfs %d\n", node);
    lowlink[node] = cas;
    dfsNum[node] = cas++;
    for(auto sosed : sosedi[node]){
        if(dfsNum[sosed] == 0){//neobiskano
            children[node].pb(sosed);
            parent[sosed] = node;
            dfs(sosed);
            lowlink[node] = min(lowlink[node], lowlink[sosed]);
            if(lowlink[sosed] > dfsNum[node]){
                bridges.insert(mp(sosed, node));
                bridges.insert(mp(node, sosed));
            }
        }
        if(sosed!=parent[node]){
            lowlink[node] = min(lowlink[node], dfsNum[sosed]);
        }
    }

    
    vector<int> candid;
    candid.pb(0);
    candid.pb(0);
    for(auto child : children[node]){
        int val = 0;
        val += bridgeAmountOne[child];
        if(bridges.count(mp(node, child))) val++;
        candid.pb(val);
    }
    sort(all(candid));
    reverse(all(candid));
    bridgeAmountOne[node] = candid[0];
    bridgeAmountTwo[node] = candid[0] + candid[1];
    
}

int main(){
    cin >> N >> M;

    loop(i, M){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    //nastavi arraye
    loop(i, nlimit){
        lowlink[i] = 0;
        dfsNum[i] = 0;
        parent[i] = -1;
        bridgeAmountOne[i] = 0;
        bridgeAmountTwo[i] = 0;
    }

    dfs(1);

    int top = 0;
    FOR(i, 1, N){
        top = max(top, bridgeAmountTwo[i]);
    }

    
    printf("mostovi\n");
    for(auto most : bridges){
        printf("%d %d\n", most.fs, most.sc);
    }


    return 0;
}