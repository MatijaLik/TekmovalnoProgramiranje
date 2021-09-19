/**
 * Author: MatijaL
 * Time: 2021-06-20 12:09:30
**/

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
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;


struct FenwickTree{
    vector<map<int, int>> v;
    int n;

    FenwickTree(int sz){
        v.resize(sz+1);
        n = sz;
    } 

    void ADD(int time, int x){
        for(; time <= n; time += time & -time){
            v[time][x]++;
        }
    }

    void SUB(int time, int x){
        for(; time <= n; time += time & -time){
            v[time][x]--;
        }
    }

    int QUERY(int time, int x){
        int res = 0;
        for(; time > 0; time -= time & -time){
            res += v[time][x];
        }
        return res;
    }
};


void solve(){
    int q;
    cin >> q;
    set<int> compS;
    map<int, int> comp;

    vector<int> a(q), t(q), x(q);
    loop(i, q){
        int A, T, X;
        cin >> A >> T >> X;
        a[i] = A;
        t[i] = T;
        x[i] = X;
        compS.insert(T);
    }

    int id = 1;
    for(auto e : compS) comp[e] = id++;
    loop(i, t.size()) t[i] = comp[t[i]];

    FenwickTree f(100500); 
    loop(i, q){
        if(a[i] == 1) f.ADD(t[i], x[i]);
        else if(a[i] == 2) f.SUB(t[i], x[i]);
        else cout << f.QUERY(t[i], x[i]) << endl;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
