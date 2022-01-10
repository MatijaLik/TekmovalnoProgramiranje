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
    int cnt[3]  = {0, 0, 0};
    int mode = 1;
    cin >> n;
    while(n--){
        string m, s;
        cin >>m >> s;
        if(m == "section"){
            mode = 1;
            cnt[0]++;
            cnt[1] = 0;
            cnt[2] = 0;
        }else if(m == "subsection"){
            mode = 2;
            cnt[1]++;
            cnt[2] = 0;
        }else{
            mode = 3;
            cnt[2]++;
        }

        if(mode == 1) printf("%d %s\n", cnt[0], s.c_str());
        else if(mode ==2) printf("%d.%d %s\n", cnt[0], cnt[1], s.c_str());
        else printf("%d.%d.%d %s\n", cnt[0], cnt[1], cnt[2], s.c_str());
    }
    return;
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}