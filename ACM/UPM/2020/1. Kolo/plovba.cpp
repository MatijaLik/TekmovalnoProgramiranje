
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl
 
#define nlimit 1100
 
ll N;
ll price [nlimit][nlimit];
 
ll memo [nlimit][nlimit][2];
 
ll dp(ll left, ll right, int orient){
    //printf("left %d right %d wiht orient %d\n", left, right, orient);
 
    //trenutno se nahajamo v tocki 
    // obiskali smo vse med left in right (inkluzivno)
    if(memo[left][right][orient] != -1) return memo[left][right][orient];
    memo[left][right][orient] = 0;
    ll curPos;
    ll optimal = 0;
 
    if(orient) curPos = right;
    else curPos = left;
    if(orient){
 
        ll sosed = (curPos + 1)%N; 
        if(sosed == left) return memo[left][right][orient] = 0;
        //sosed
        if(price[curPos][sosed]!= -1){
            optimal = max(optimal, price[curPos][sosed] + dp(left, sosed, 1));
        }
 
        //preko
        ll across = left - 1;
        if(across < 0) across += N;
        while(across != right){
            if(price[curPos][across]!= -1){
                //cout << "across" << endl;
                optimal = max(optimal, price[curPos][across] + dp(across, right, 0));
            }
 
            across --;
            if(across < 0) across += N;
        }
        
        
    }else{
        ll sosed = left - 1;
        if(sosed < 0) sosed += N;
 
        if(sosed == right) return memo[left][right][orient] = 0;
        //sosed
        if(price[curPos][sosed]!= -1){
            optimal = max(optimal, price[curPos][sosed] + dp(sosed, right, 0));
        }
 
        //preko
        ll across = (right + 1)%N;
        while(across != left){ 
            
            if(price[curPos][across]!= -1){
                //cout << "across to "  << across << endl;
                optimal = max(optimal, price[curPos][across] + dp(left, across, 1));
            }
            across = (across+1)%N;
        }
    }
    
    
    //printf("RESULT left %d right %d orient %d ===> %d\n", left, right, orient, optimal);
    return memo[left][right][orient] = optimal;
}
 
 
 
int main(){
    cin >> N;
    loop(i, N)loop(j, N){
        cin >> price[i][j];
        memo[i][j][0] = -1;
        memo[i][j][1] = -1;
    }
 
    loop(i, N){
        cout << max(dp(i, i, 1), dp(i, i, 0)) << " ";
    }
    cout << endl;
 
 
}
