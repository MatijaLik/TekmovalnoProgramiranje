/**
 * Author: MatijaL
 * Time: 2022-02-26 21:51:12
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
typedef long double ld;
    
void solve(){
    int n, p;
    cin >> n >> p;
    ld cnt[21];
    memset(cnt, 0, sizeof cnt);
    
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        int len=0;
        int j=i;
        while((s[j]!='*') && (len <= 20)){
            cnt[len]++;
            len++;
            j = (j+1)%n;
        }
    }
    ld prob[21];
    prob[0]=cnt[0]/n;
    for(int i=1;i<=20;i++)
        prob[i] = cnt[i]/cnt[i-1];
    
    stringstream ans;
    int step=1;
    ld sur=1;
    
    sur *= prob[0];
    loop(i, p-1){
        if(prob[step]>prob[0]){
            ans << "FIRE" << endl;
            sur *= prob[step];
            step++;
        }else{
            ans << "ROLL" << endl;
            sur *= prob[0];
            step=1;
        }
    }
    
    printf("%.10Lf\n", sur);
    cout << ans.str();
}

int main(){

    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();   
}
