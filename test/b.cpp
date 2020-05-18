#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    ll n, m;
    cin >> n >> m;
    if(n == 1) cout << 0 << endl;
    else if(n == 2) cout << m << endl;
    else cout << 2 * m << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}