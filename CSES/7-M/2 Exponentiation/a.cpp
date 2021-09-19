#include<bits/stdc++.h>
using namespace std;
const long long  mod = 1000000007;



long long binPow(long long a, long long b, long long m){
    long long ans = 1;
    if(a == 0 and b != 0){
        return 0;
    }
    while(b > 0){
        if(b % 2) ans *= a;
        b /=2;
        a *= a;
        a %= m;
        ans %= m;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;
        cout << binPow(a, binPow(b, c, mod-1), mod) << endl;
    }
    return 0;
}