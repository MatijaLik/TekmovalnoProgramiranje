#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll K;
    cin >> K;

    if(K==0){
        cout << 1 << " " << 1 << endl;
        cout << 69 << endl;
        return 0;
    }

    ll ugly, zero, bad, good;//poimenovanje 100

    if(K%2 == 0){
        zero = 1;
        ugly = K+1;
    }else{
        zero = (1 << 17);
        ugly = K;
    }
    

    for(int i = 17; i >= 0; i--){
        if(ugly & (1 << i)){
            bad = (1 << i+1);
            break;
        }
    }
    good = bad + ugly;

    printf("3 3\n");
    printf("%d %d %d\n", good, ugly, zero);
    printf("%d %d %d\n", bad, ugly, zero);
    printf("%d %d %d\n", bad, good, ugly);

}