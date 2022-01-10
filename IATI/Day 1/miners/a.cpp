#include<bits/stdc++.h>
using namespace std;
#define pb push_back

#define ll long long
#define limit 100500
#define INF 1e16

#define fs first
#define sc second

int tin[limit], tout[limit];
ll source[limit], sink[limit];

int cas = 0;
ll weight[limit];
vector<int> otroci[limit];

void dfs(int node){
    tin[node] = ++cas;
    for(auto e : otroci[node]) dfs(e);
    tout[node] = ++cas;
}

ll a[2*limit];
ll cumsum[2*limit];

ll rangeSum(int l, int r){
    if(l > r) assert(0);
    return cumsum[r] - cumsum[l-1];
}

ll pathSum(int a, int b){
    if(tin[a] < tin[b] && tout[b] < tout[a])return rangeSum(tin[a]+1, tin[b]);
    else return -INF;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i =1;i<=N;i++) cin >> source[i];
    for(int i =1;i<=N;i++) cin >> sink[i];
    for(int i =2;i<=N;i++){
        int p, w;
        cin >> p >> w;
        weight[i] = w;
        otroci[p].pb(i);
    }

    dfs(1);
    for(int i = 2;i<=N;i++){
        a[tin[i]] = weight[i];
        a[tout[i]] = -weight[i];
    }
    for(int i = 1; i < 2*limit;i++){
        cumsum[i] = cumsum[i-1] + a[i];
    }

    
    priority_queue<pair<ll, pair<int, int>>> pq;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(i==j) continue;
            ll score = pathSum(i, j);
            if(score == -INF) continue;
            pq.push(make_pair(score, make_pair(i, j)));
        }
    }

    ll ans = 0;
    while(!pq.empty()){
        auto e = pq.top();
        pq.pop();

        ll score = e.fs;
        ll a = e.sc.fs;
        ll b = e.sc.sc;
        
        ll people = min(source[a], sink[b]);
        assert(people>=0);
        
        //printf("%lld | %lld-%lld| %lld\n", score, a, b, people);
        if(score <= 0) continue;
        if(people == 0) continue;

        ans += people*score;
        source[a] -= people;
        sink[b] -= people;
    }
    assert(ans >= 0);
    cout << ans << endl;
}