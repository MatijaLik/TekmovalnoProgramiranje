#include<stdio.h>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    int pravda = 0;
    if(N > 650){
        pravda += (N - 650)*5;
        N = 650; 
    }
    if(N > 150){
        pravda += (N - 150)*2;
        N = 150;
    }

    pravda += N;
    printf("%d\n", pravda);
}