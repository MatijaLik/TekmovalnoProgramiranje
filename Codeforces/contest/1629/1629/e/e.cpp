/**
 * Author: MatijaL
 * Time: 2022-01-22 15:35:03
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
    int a[N][N];
    loop(i, N)loop(j, N) cin >> a[i][j];
    int color[N][N];
    memset(color, 0, sizeof color);
    //barvajmo
    FOR(i, 0,N-1) color[0][i] = 1;
    for(int h=0;h<N-1;h++){
        for(int w=0;w<N;w++){
            int white=0;
            if(h!=0&&!color[h-1][w])white++;
            if(w!=0&&!color[h][w-1])white++;
            if(w!=N-1&&!color[h][w+1])white++;
            if(h!=N-1&&!color[h+1][w])white++;
            if(white%2==0) color[h+1][w]=1;
        }
    }
    int ans = 0;
    FOR(i, 0, N-1){
        FOR(j, 0, N-1){
            if(!color[i][j])
                ans ^= a[i][j];
            //cout << color[i][j] << " ";
        }
        //cout << endl;
    }
            
    cout << ans << endl;
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
