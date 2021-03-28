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
vector<int> sosedi[400100];
vector<int> prop[400100];
int root = 1;
#define DEBUG 0

vector<pll> ans;

void dfs2(int node, int prev){


    if(DEBUG) cout << "dfs2 " << node << endl;

    //Preveri ce si list
    if(sosedi[node].size() == 1){
        vector<int> v;
        v.pb(node);
        //vrni sebe
        prop[node] = v;
        return;
    }

    //porihtaj ostalo
    vector<int> v;
    priority_queue<pll> pq;

    for(auto e : sosedi[node]){
        if(e == prev) continue;
        dfs2(e, node);
        v.pb(e);
    }

    //ce smo na ravni crti samo propagiraj dalje
    if(v.size() == 1){
        prop[node] = prop[v[0]];
    }

    int numberOfElements = 0;

    //naredi tage
    loop(i, v.size()){
        pq.push(mp(prop[v[i]].size(), v[i]));
        numberOfElements += prop[v[i]].size();
    }


    while(numberOfElements > 2){
        pll tag1 = pq.top();
        pq.pop();

        pll tag2 = pq.top();
        pq.pop();

        //povezi oba elementa
        int a = prop[tag1.sc][tag1.fs-1];
        tag1.fs--;

        int b = prop[tag2.sc][tag2.fs-1];
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
        toReturn.pb(prop[tag1.sc][0]);
        if(tag1.fs == 2){
            toReturn.pb(prop[tag1.sc][1]);
        }else if(!pq.empty()){
            pll tag2 = pq.top();
            pq.pop();
            toReturn.pb(prop[tag2.sc][0]);
        }
        

        prop[node] = toReturn;
    }else{
        //povezemo
        if(numberOfElements == 2){
            pll tag1 = pq.top();
            pq.pop();
            int a = prop[tag1.sc][0];
            int b;
            if(tag1.fs == 2){
                b = prop[tag1.sc][1];
            }
            else if (!pq.empty())
            {
                pll tag2 = pq.top();
                pq.pop();
                b = prop[tag2.sc][0];
            };

            //povezi oba elementa

            ans.pb(mp(a, b));
            if(DEBUG) cout << a << " " << b << endl;
        }else{
            //samo en element je ostal
            pll tag = pq.top();
            int a = prop[tag.sc][0];
            int b = ans[0].fs;
            ans.pb(mp(a, b));
            if(DEBUG) cout << a << " " << b << endl;
        }
    }

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
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << endl;
        return;
    }else if(n == 0){
        cout << 0 << endl;
    }
    loop(i, n-1){
        int a, b;
        cin >> a >> b;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    FOR(i, 1, n) prop[i].reserve(3);

    //najdi neki spodobni root
    while(sosedi[root].size() == 1) root++;
    if(DEBUG) cout << "root is " << root;
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
