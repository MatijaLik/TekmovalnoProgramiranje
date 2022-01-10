#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int N, S, C;
    cin >> N >> S >> C;
    int P = S+C;
    int r=1;
    vector<int> ans;
    int time = 0;

    if(S==0){
        for(int i = 0; i <(N/2)+1;i++) ans.pb((N+1)/2);
    }
    else{
        while(1){
            if(r>=N){
                ans.pb(N);
                break;
            }
            if(time%P < S) {ans.pb(r);r+=2;}
            else {ans.pb(N);r++;}
            time++;
        }
    }
    cout << ans.size() << endl;
    for(auto e : ans) cout << e << ' ';
    cout << endl;
}