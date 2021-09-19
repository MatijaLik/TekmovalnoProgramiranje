#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int ex = 1; ex <= 30; ex++)
        ans += n / (1<<ex);
    cout << ans << endl;
}