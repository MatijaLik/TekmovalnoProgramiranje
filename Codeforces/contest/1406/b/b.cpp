/**
 * Author: MatijaL
 * Time: 2020-09-12 15:45:01
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
const ll INF = 4000000000000000000;
vector<ll> neg, pos;
int t;
ll calc(int nn, int pn){
   if(neg.size() < nn) return -INF;
   if(pos.size() < pn) return -INF;
   ll prod = 1;
   loop(i, nn) prod *= neg[i];
   loop(i, pn) prod *= pos[i];
   return prod;
}
void solve(int T){
    neg.clear();
    pos.clear();
    int n;
    cin >> n;
    loop(i, n){
        ll temp;
        cin >> temp;
        if(temp < 0) neg.pb(temp);
        else pos.pb(temp);
    }
    sort(all(pos));
    sort(all(neg));
    reverse(all(pos));
    ll best = -INF;
    loop(i, 6){
        best = max(best, calc(i, 5-i));
    }
    if(pos.size() == 0){
        ll h = 1;
        reverse(all(neg));
        loop(i, 5) h *= neg[i];
        best = h;
    }
    cout << best << endl;
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    loop(i, t) solve(i);   
}
