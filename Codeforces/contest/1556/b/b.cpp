/**
 * Author: MatijaL
 * Time: 2021-08-29 16:35:02
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


ll eval(vector<int> v, int len, int par){
    queue<ll> odd;
    queue<ll> even;
    

    ll cost = 0;
    loop(i, len){
        int e = v[i];
        if(e%2) odd.push(i);
        else even.push(i);
    }
    loop(i, len){
        if(i%2 == par){
            cost += abs(i - odd.front());
            odd.pop();
        }else{
            cost += abs(i - even.front());
            even.pop();
        }
    }

    return cost;
}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i, n) cin >> v[i];
    
    ll cnto=0,cnte=0;
    for(auto e :v ){
        if(e % 2)cnto++;
        else cnte++;
    }

    if(max(cnte, cnto) - min(cnte, cnto) > 1){
        cout << -1 << endl;
        return;
    }

    if(n%2){
        ll sum = 0;
        if(cnto > cnte){
            sum =eval(v, n, 0);
        }else sum  = eval(v, n, 1);


        cout << sum/2 << endl;
    }else{

        cout << min(eval(v, n, 0), eval(v, n, 1))/2 << endl;
        
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
