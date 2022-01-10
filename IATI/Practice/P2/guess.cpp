#include "guess.h"
void guess(){
    long long l=1;
    long long r=1e18;
    long long m;
    while(1){
        m = (l+r)/2;
        if(l==r){
            res(m);
            return;
        }
        int a = quest(m);
        if(a == 1) l = m+1;
        if(a == 2) r = m-1;
        if(a == 0) {
            res(m);
            return;
        }
    }
}