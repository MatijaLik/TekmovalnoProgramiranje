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



int main(){
    ios::sync_with_stdio(0);

    cin.tie(0);
    set<ll> napraveS;
    vector<ll> vseNaprave;
    priority_queue<pair<pll, ll>> q;



    map<ll, ll> cur;
    map<ll, ll> top;


    ll K;
    cin >> K;
    loop(a, K){
        ll s, e, id;
        cin >> s >> e >> id;
        if(napraveS.count(id)==0){
            napraveS.insert(id);
            vseNaprave.pb(id);
        }
        q.push(mp(mp(-s, -1), id));
        q.push(mp(mp(-e, 0), id));
    }

    while(!q.empty()){
        pair<pll, ll> p = q.top();
        q.pop();

        ll time = -p.fs.fs;
        ll type = -p.fs.sc;
        ll id = p.sc;

        if(type){
            cur[id]++;
            top[id] = max(top[id], cur[id]);
        }else{
            cur[id]--;
        }
        //printf("%d %d %d %d\n", time, type, id, cur[id]);
    }

    sort(all(vseNaprave));
    for(auto id: vseNaprave){
        cout << id << " " << top[id] << endl;
    }
}