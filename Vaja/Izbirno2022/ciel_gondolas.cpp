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

//Divide and conquer DP


vector<int> dp_prev(5000+1, 0);
vector<int> dp_cur(5000+1);
int C[4005][4005];


void d_a_c_dp(int l, int r, int optl, int optr){
    if(l>r) return;
    int mid = (l+r)/2;
    
    
    dp_cur[mid] = inf;
    int opt=-1;
    for(int i=optl; i<=min(optr, mid-1); i++){
        if(dp_prev[i] + C[i+1][mid] < dp_cur[mid]){
            dp_cur[mid] = dp_prev[i] + C[i+1][mid];
            opt=i;
        }
    }
    //printf("dp %d-%d = %d| %d %d | %d\n", l, r,mid, optl, optr, opt);
    if(l!=r){
        d_a_c_dp(l, mid-1, optl, opt);
        d_a_c_dp(mid+1, r, opt, optr);
    }
}


int main(){
    int a[4005][4005];
    int cs[4005][4005];
    
    int N, K;
    scanf("%d %d", &N, &K);
    getchar();
    FOR(i, 1, N){
        FOR(j, 1, N){
            a[i][j] = getchar()-'0';
            getchar();
        }
    }


    FOR(i, 0, N) {cs[0][i]=0;cs[i][0]=0;}
    FOR(i, 1, N){
        FOR(j, 1, N){
            cs[i][j] = a[i][j] + cs[i-1][j] + cs[i][j-1] - cs[i-1][j-1];
        }
    }
    
    FOR(a, 1, N){
        FOR(b, a, N){
            C[a][b] = cs[b][b] - cs[a-1][b] - cs[b][a-1] + cs[a-1][a-1];
            C[a][b] /=2;
        }
    }
    
    FOR(n, 1, N)
        dp_cur[n]=C[1][n]; 
    dp_prev=dp_cur;

    FOR(k, 2, K){
        d_a_c_dp(1, N, 1, N-1);
        dp_prev=dp_cur;
    }
    printf("%d\n",dp_cur[N]);
    return 0;
}
