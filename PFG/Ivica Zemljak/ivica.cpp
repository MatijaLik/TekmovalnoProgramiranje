#include<stdio.h>
using namespace std;
typedef long long ll;
int main(){
    int k;
    scanf("%d", &k);

    ll opt=5'000'000'000;
    for(ll d=1; d*d<=k;d++){
        if(k%d==0){
            ll a = d;
            ll b = k/d;
            ll obseg = 2*a +2*b;
            if(obseg<opt)
                opt = obseg;
        }
    }
    printf("%d\n", opt);
}