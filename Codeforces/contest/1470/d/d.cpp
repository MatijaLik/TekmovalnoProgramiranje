/**
 * Author: MatijaL
 * Time: 2021-01-08 18:21:09
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

#define limit 300100

vector<int> sosedi[limit];

int bcnt = 0;
int color[limit];
void solve(){
    int n, m;
    bcnt = 0;
    cin >> n >> m;
    loop(i, n+10) sosedi[i].clear();
    loop(i, n+10) color[i] = 0;
    loop(i, m){
        int a, b;
        cin >> a >>b ;
        sosedi[a].pb(b);
        sosedi[b].pb(a);
    }

    //is connected???
    int cnt = 1;
    queue<int> q;
    q.push(1);
    color[1] = 1;
    bcnt++;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(color[node] == 1){
            for(auto e : sosedi[node]){
                if(color[e] == 0){
                    color[e] = 2;
                    q.push(e);
                    cnt++;
                }                
                color[e] = 2;
            }
        }
        if(color[node] == 2){
            for(auto e : sosedi[node]){
                if(color[e] == 0){
                    cnt++;
                    color[e] = 1;
                    q.push(e);
                    bcnt++;
                    q.push(node);
                    break;
                }
            }
        }
    }
    if(cnt == n){
        cout << "YES" << endl;
        bcnt = 0;
        FOR(i, 1, n) if(color[i] == 1) bcnt++;
        cout << bcnt << endl;
        FOR(i, 1, n){
           
            if(color[i] == 1) cout << i << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
