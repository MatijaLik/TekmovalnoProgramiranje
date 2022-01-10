#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, t;
    cin >> n >> t;
    vector<long long> naprave(n);
    for(int i=0;i<n;i++){
        cin >> naprave[i];
    }
    
    long long l = 1;
    long long r = 1e18;
    long long m;
    while(l!=r){
        m = (l+r)/2;
        long long s = 0;
        for(auto e : naprave) {
            s += m/e;
            if(s >= t){
                r = m;
                break;
            }
        }
        if(s < t) l = m+1;
        else r = m;
        
    }
    m = (l+r)/2;
    cout << m << endl;
}
