/**
 * Author: MatijaL
 * Time: 2022-03-05 15:00:26
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
    string a;
    cin >> a;
    map<char, int> m;
    bool side=0;
    int mul=1;
    char prev = 0;
    for(auto e : a){
        if(e=='-' or e=='>') {side=1;mul=1;prev=0;}
        else if(e == '+') {mul=1; prev=0;}
        else if(e >=48 and e <=57){
            if(mul==1 and prev==0) mul = e-'0';
            else{
                if(side){
                    m[prev]-=mul*(e-'1');
                }else{
                    m[prev]+=mul*(e-'1');
                }
            }
        }else{
            assert(e >= 65 and e <=90);
            prev=e;
            if(side){
                m[e]-=mul;
            }else{
                m[e]+=mul;
            }
        }
    }

    for(auto &[key, num] : m){
        //cout << key << " " << num << endl;
        if(num!=0){
            cout << "NE" << endl;
            return;
        }
    }
    cout << "DA" << endl;
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
