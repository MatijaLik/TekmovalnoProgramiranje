/**
 * Author: MatijaL
 * Time: 2020-11-21 15:35:02
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

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    loop(i, q){
        int l, r;
        cin >> l >> r;
        int len = r -l +1;
        string sub;
        FOR(i, l, r)sub += s[i-1];
        
        if(len < 2){
            cout << "NO" << endl;
            continue;
        }

        //cout << sub << endl;

        int psub = 0;
        bool cont = false;
        bool started = false;
        for(auto e : s){
            if(psub == len) break;
            char search = sub[psub];
            if(e != search and started){
                cont = true;
                continue;
            }
            if(psub == len-1 and cont == false){
                cont = true;
                continue;
            }
            if(e == search){
                psub++;
                started = true;
            }
        }

        if(cont and psub == len) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
