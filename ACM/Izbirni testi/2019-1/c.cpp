
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
int K, N, D;

ll base[6];
vector<string> DATA;
const int cases = 1050000;

map<pair<int, int>, pair<int, string>> memo;
bool visited[cases][51];

int HASH(vector<int> v){
    int res = 0;
    reverse(all(v));
    for(auto e : v){
        res *= 16;
        res += e;
    }
    return res;
}

vector<int> DEHASH(int hash){
    vector<int> v;
    loop(i, K){
        v.pb(hash % 16);
        hash /= 16;

    }
    return v;
}

int getMax(vector<int> v){
    int mx = 0;
    for(auto e : v) mx = max(mx, e);
    return mx;
}




pair<int, string> dp(int hash, int pos){
    if(visited[hash][pos]) return memo[mp(hash, pos)];
    if(pos == N) return memo[mp(hash, pos)] = mp(getMax(DEHASH(hash)), "");
   
    //loop(i, indent) printf("|  ");
    //printf("dp %d %d\n", hash, pos);
    visited[hash][pos] = true;
    vector<int> cost = DEHASH(hash);
    if(getMax(cost) > D) return mp(inf, "");
    int best = inf;
    string bestStr;
    //test both cases
    loop(bit, 2){
        char c;
        if(bit) c = '1';
        else c = '0';
        vector<int> costCopy = cost;
        loop(i, K){
            if(DATA[i].at(pos) != c) costCopy[i]++;
        }
        if(getMax(costCopy) > D) continue;

        pair<int, string> p = dp(HASH(costCopy), pos+1);
        if(p.fs < best){
            best = p.fs;
            bestStr = c + p.sc;
        }
    }
    //loop(i, indent) printf("|  ");
    //cout << best << " " << bestStr << endl;
    return memo[mp(hash, pos)] = mp(best, bestStr);
}
void solve(){
    cin >> K >> N >> D;
    loop(i, K){
        string s;
        cin >> s;
        DATA.pb(s);
    }
    base[0] = 1;
    FOR(i, 1, 5) base[i] = base[i-1] * 16;
    pair<int, string> p = dp(0,0);
    cout << p.fs << endl;
    cout << p.sc << endl;
}
int main(){
 
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
