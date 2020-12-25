/**
 * Author: MatijaL
 * Time: 2020-11-16 09:30:26
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

void solve(){
    int N;
    cin >> N;
    vector<ll> v(N);
    loop(i, N)cin >> v[i];
    ll sum = 0;
    loop(i, N) sum += v[i];
    if(sum % N){
        cout << -1 << endl;
        return;
    }

    ll G = sum/N;
    stringstream ans;
    ll ansCnt = 0;


    loop(i, N-1){
        FOR(pos, 1, N-1){
            if(v[pos] == 0) continue;
            ll need = (pos+1) - (v[pos] % (pos+1));
            if(need == (pos+1)) need = 0;
            if(v[0] >= need){
                ansCnt += 2;
                ans << 1 << " " << pos+1 << " " << need << endl;
                ans << pos+1 << " " << 1 << " " << (need+v[pos])/(pos+1) << endl;
                v[0] += v[pos];
                v[pos] = 0;
                break;
            }
        }
        //print(v);
    }

    FOR(pos, 1, N-1){
        if(v[0] >= 2*G){
            ansCnt += 1;
            ans << 1 << " " << pos+1 << " " << G << endl;
            v[0] -= G;
            v[pos] += G;
        }
        //print(v);
    }



    //preveri
    for(auto e : v) if(e != G){
        cout << -1 << endl;
        return;
    }
    cout << ansCnt << endl;
    cout << ans.str();
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
