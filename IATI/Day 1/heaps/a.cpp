#include<bits/stdc++.h>
using namespace std;

#define limit 1020

bool dp(int a, int b){
    bool ans = 0;
    if(a == 0 && b == 0) return false;
    if(a>0)ans |= dp(a-1, b);
    if(b>0){
        ans |= dp(a, b-1);
        ans |= dp(a+1, b-1);
    }
    return ans;
}
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    //K = 0
    int K, Q;
    cin >> K >> Q;

    bool DP[limit][limit];
    memset(DP, 0, sizeof DP);

    DP[0][0] = false;
    for(int b = 0; b < limit-10;b++){
        for(int a = 0; a<limit-10;a++){
            if(DP[a][b]==false){
                DP[a+1][b] = true;
                DP[a][b+1] = true;
                if(a>0) DP[a-1][b+1] = true;
            }
        }
    }

    for(int q =0;q<Q;q++){
        int N;
        cin >> N;
        int x=0, y=0;
        for(int i = 0;i<N;i++){
            int b, s;
            cin >> b >> s;
            if(s == 1) x++;
            else if(s > 0) y++;
        }
        if(DP[x][y]) cout << "Win" << endl;
        else cout << "Lose" << endl;
    }
}