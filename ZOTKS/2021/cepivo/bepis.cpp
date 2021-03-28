/**
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
#warning ko oddas daj vec spomina
vector<int> sosedi[200010];

int root = 1;
#define DEBUG 0

vector<pll> ans;

vector<int> dfs2(int node, int prev){


    if(DEBUG) cout << "dfs2 " << node << endl;

    //Preveri ce si list
    if(sosedi[node].size() == 1){
        vector<int> v;
        v.pb(node);
        //vrni sebe
        return v;
    }

    //porihtaj ostalo
    vector<vector<int>> v;
    priority_queue<pll> pq;
    for(auto e : sosedi[node]){
        if(e == prev) continue;
        v.pb(dfs2(e, node));
    }

    //ce smo na ravni crti samo propagiraj dalje
    if(v.size() == 1) return v[0];

    int numberOfElements = 0;

    //naredi tage
    int T = v.size();
    loop(i, T){
        pq.push(mp(v[i].size(), i));
        numberOfElements += v[i].size();
    }


    while(numberOfElements > 2){
        pll tag1 = pq.top();
        pq.pop();

        pll tag2 = pq.top();
        pq.pop();

        //povezi oba elementa
        int a = v[tag1.sc][tag1.fs-1];
        tag1.fs--;

        int b = v[tag2.sc][tag2.fs-1];
        tag2.fs--;

        ans.pb(mp(a, b));
        numberOfElements -= 2;

        if(DEBUG) cout << a << " " << b << endl;
        //damo nazaj
        if(tag1.fs) pq.push(tag1);
        if(tag2.fs) pq.push(tag2);
    }

    if(node != root){
        
        vector<int> toReturn;
        
        //vrnemo ostanek
        pll tag1 = pq.top();
        pq.pop();
        toReturn.pb(v[tag1.sc][0]);

        if(!pq.empty()){
            pll tag2 = pq.top();
            pq.pop();
            toReturn.pb(v[tag2.sc][0]);
        }
        

        return toReturn;
    }else{
        //povezemo
        if(pq.size() == 2){
            pll tag1 = pq.top();
            pq.pop();

            pll tag2 = pq.top();
            pq.pop();

            //povezi oba elementa
            int a = v[tag1.sc][tag1.fs - 1];

            int b = v[tag2.sc][tag2.fs - 1];

            ans.pb(mp(a, b));
            if(DEBUG) cout << a << " " << b << endl;
        }else{
            //samo en element je ostal
            pll tag = pq.top();
            int a = v[tag.sc][0];
            int b;
            if(ans.size() > 0) b = ans[0].fs;
            else b = a;
            ans.pb(mp(a, b));
            if(DEBUG) cout << a << " " << b << endl;
        }
    }

    vector<int> dummy;
    return dummy;
}

void solve(){

    int n;
    cin >> n;
    
    if(n==1){
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }else if(n == 2){
        cout << 1 << endl;
        cout << "1 2" << endl;
        return;
    }
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    //najdi neki spodobni root
    while(sosedi[root].size() == 1) root++;

    dfs2(root, 0);


    cout << ans.size() << endl;
    for(auto e: ans) cout << e.fs << " " << e.sc << endl;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--) solve();   
}
