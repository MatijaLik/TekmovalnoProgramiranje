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


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int amnt = 0;
    stack<int> zero;
    stack<int> one;

    vector<ll> ans;


    int i = 0;

    for(auto c : s){
        if(c == '0'){
            if(one.empty()){
                amnt++;
                zero.push(amnt);
                ans.pb(amnt);
            }else{
                int num = one.top();
                one.pop();
                zero.push(num);
                ans.pb(num);
            }
        }else{
            if(zero.empty()){
                amnt++;
                one.push(amnt);
                ans.pb(amnt);
            }else{
                int num = zero.top();
                zero.pop();
                one.push(num);
                ans.pb(num);

            }
        }
    }
    cout << amnt << endl;
    for(auto e : ans){
        cout << e << " ";
    }
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)solve();   
}