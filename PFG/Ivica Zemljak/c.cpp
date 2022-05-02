#include<stdio.h>
using namespace std;
int main(){
    
    bool precrtano[105001];
    int prastevila[10001];
    
    int kazalec = 1;
    
    for(int i=0; i<=105000; i++){
        precrtano[i] = false;
    }
    
    // 0 1 2 3 4 5 6 7 ... 100
    // F F F F F F F F
    
    for(int i=2; i<=105000; i++){
        if(precrtano[i]==false){
            //printf("%d\n", i);
            
            prastevila[kazalec] =  i;
            kazalec += 1;
            
            if(kazalec == 10001){
                break;
            }
            
            for(int v= 2*i; v<=105000; v += i){
                precrtano[v] = true;
            }
        }
    }
    
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d", &n);
        int prod = 1;
        for(int i=0; i<n;i++){
            int d;
            scanf("%d",&d);
            prod *= prastevila[d];
        }
        printf("%d\n", prod);
    }
    
}
