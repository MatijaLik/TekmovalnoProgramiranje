#include<stdio.h>
using namespace std;

int main(){
    int k;
    scanf("%d", &k);
    
    int najmansji_obseg = 2000000010;
    
    for(int i=1; i<=k; i++){
        
        // a = 15
        // i = 1..2..3..4..5
        if(i > k/i){
            break;
        }
        
        
        if(k%i == 0){
            int obseg = 2*(i+k/i);
            if(obseg<najmansji_obseg){
                najmansji_obseg = obseg;
            }
            //printf("%d x %d ---> %d\n", i, k/i, obseg);
        }
    }
    
    printf("%d\n", najmansji_obseg);
    
}
