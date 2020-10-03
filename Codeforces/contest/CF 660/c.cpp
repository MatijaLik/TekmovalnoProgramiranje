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
#define inf 1000000000
#define mod 1000000007
 
 
#define limit 200100
 
int parent[limit];
 
vector<ll> sosedi[limit];
 
//passing through
//koliko ljudi bo senzor izmeril
ll pt[limit];
 
 
//stevilo veselih in sad
ll h[limit];
ll s[limit];
 
ll pop[limit];
ll sensor[limit]; //sensor reading
 
bool error = 0;
 
void dfs1(int node){
    pt[node] = pop[node];
    
    ll hSum = 0;
    ll sSum = 0;
    ll sensorSum = 0;
 
    for(auto sosed : sosedi[node]){
        if(parent[sosed] == 0){
            parent[sosed] = node;
            dfs1(sosed);
            pt[node] += pt[sosed];
            
            hSum += h[sosed];
            sSum += s[sosed];
            sensorSum += sensor[sosed];
        }
    }
    
    h[node] = (pt[node] + sensor[node])/2;
    s[node] = h[node] - sensor[node];
 
 
    //1. check
    if(h[node] > pt[node]) error = 1;
    if(s[node] > pt[node]) error = 1;
 
    //gone sad
    ll deltaMood = sensorSum - sensor[node];
    //printf("Node %d | h %lld | s %lld | hSum %lld | sSum %lld | sensor %lld | sensorSum %lld | deltaMood %lld\n", node, h[node], s[node], hSum, sSum, sensor[node], sensorSum,deltaMood);
 
    ll maoficl = max(pop[node] - s[node], (ll)0);
 
    //3 check
    if(deltaMood < -( 2*h[node] - maoficl)) error = 1;//cim vec veselih postane sad na poti
 
    if(deltaMood > min(pop[node], s[node])) error = 1;//vse sad pustimo
 
    //2. check
    if(hSum > h[node]) error = 1;
    if(sSum < s[node] - pop[node]) error = 1;
    if(sSum + hSum != h[node] + s[node] - pop[node]) error = 1;
 
    //if(error) printf("ERROR!\n");
}
 
 
bool solve(){
    error = 0;
    ll n, m;
    cin >> n >> m;
 
    loop(i, n+10){
        parent[i] = 0;
        sosedi[i].clear();
        pt[i] = 0;
        h[i] = 0;
        s[i] = 0;
    }
 
    
    
    FOR(i, 1, n){
        ll p;
        cin >> p;
        pop[i] = p;
    }
 
    FOR(i, 1, n){
        ll sen;
        cin >> sen;
        sensor[i] = sen;
    }
 
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }
 
    //naredi drevo
    parent[1] = -1;
    dfs1(1);
 
 
    if(error) return 0;
    else return 1;
}
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        bool b = solve();
        if(b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
}