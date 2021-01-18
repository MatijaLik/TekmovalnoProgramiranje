/**
 * Author: MatijaL
 * Time: 2020-12-27 22:38:11
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

    int n, m;

    int a[101][101];
stringstream ss;
int ans = 0;
void inv(int i, int j){
    a[i][j] = 1-a[i][j];
    ans++;
    ss << i + 1 << " " << j+1 << " ";
}

void ssq(int i, int j){
    string s;
    if(a[i][j]) s+= '1';else s+='0';
    if(a[i][j+1]) s+= '1';else s+='0';
    if(a[i+1][j]) s+= '1';else s+='0';
    if(a[i+1][j+1]) s+= '1';else s+='0';
    
    if(s == "0000") return;
    if(s == "0001" or s == "1000" or s == "1100" or s == "1011" or s == "1111" or s == "0101" or s == "0110"){
        inv(i, j);
        inv(i+1, j);
        inv(i+1, j+1);
        ss << endl;
    }
    if(s == "0010" or s == "0100" or s == "0111" or s == "1001"){
        inv(i, j+1);
        inv(i+1, j);
        inv(i+1, j+1);
        ss << endl;
    }
    if(s == "0011" or s == "1110"){
        inv(i, j);
        inv(i, j+1);
        inv(i+1, j);
        ss << endl;
    }
    if(s == "1010" or s == "1101"){
        inv(i, j);
        inv(i, j+1);
        inv(i+1, j+1);
        ss << endl;
    }


    ssq(i, j);
}



void solve(){
    cin >> n >> m;
    loop(i, n){
        string s;
        cin >> s;
        loop(j, m){
            if(s[j] == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }    
    int benis = 0;
    if(n%2 and m%2 and a[n-1][m-1]){
        inv(n-1, m-1);
        inv(n-2, m-1);
        inv(n-1, m-2);
        ss << endl;
        benis = 1;
    }
    if(n%2){
        loop(i, m-benis){
            if(a[n-1][i] == 0) continue;
            inv(n-1, i);
            inv(n-2, i);
            if(i == 0) inv(n-2, i+1);
            else inv(n-2, i-1);
            ss << endl;
        }
    }
    if(m%2){
        loop(i, n-benis){

            if(a[i][m-1] == 0) continue;
            inv(i, m-1);
            inv(i, m-2);
            if(i == 0) inv(i+1, m-2);
            else inv(i-1, m-2);
            ss << endl;
        }
    }   

    for(int i = 0; i < n-1; i+=2){
        for(int j = 0; j < m-1; j+=2){
            ssq(i, j);
        }
    }


    cout << ans/3 << endl;
    cout << ss.str();
    ss.str("");
    ss.clear();
    ans = 0;
    /*
    loop(i, n){
        loop(j, m) cout << a[i][j];
        cout << endl;
    }*/
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
