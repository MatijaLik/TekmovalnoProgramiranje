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

#define SHIFT 400300

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(){

    }

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    int N;
    cin >> N;
    vector<int> v(N+1, 0);

    ll ans=0;


    set<int> barve;
    loop(i, N){
        cin >> v[i+1];
        barve.insert(v[i+1]);
    }
    map<int, FenwickTree()> M;

    FOR(r, 1, N){
        int cur = v[r];

        //Dodaj sebe
        if(M.count(cur)==0){
            M[cur] = Fen
        }
    }

    for(auto e : barve){
        int cum = 0;

        FenwickTree F(2*SHIFT);
        F.add(0+SHIFT,1);

        FOR(i, 1, N){
            if(v[i]==e)cum++;
            int res = F.sum(0, 2*cum-i-1+SHIFT);
            ans += res;

            F.add(2*cum-i+SHIFT, 1);
        }
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}