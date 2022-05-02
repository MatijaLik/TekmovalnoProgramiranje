/**
 * Author: MatijaL
 * Time: 2022-04-07 08:41:51
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

string a, b;

string recursion(int index, bool max, vector<char> digits){
    printf("%d \n", index);
    
    if(digits.size()==0){
        return "";
    }
    
    if(max){
        //vrni najvecjo mozno
        string ans = "";
        for(auto e : digits) ans+=e;
        return ans;
    }
    print(digits);
    for(int i=0;i<digits.size();i++){
        if(digits[i]<=b[index]){
            char vodilna = digits[i];
            digits.erase(digits.begin()+i);
            string ans = "";
            ans += vodilna;
            if(vodilna==b[index]){
                ans += recursion(index+1, false, digits);
            }else{
                ans += recursion(index+1, true, digits);
            }
            return ans;
        }
    }
}

void solve(){
    cin >> a >> b;
    if(b.length()>a.length()){
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << a << endl;
        return;
    }
    
    vector<char> v;
    for(auto e : a){
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    cout << recursion(0, false, v) << endl;
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
