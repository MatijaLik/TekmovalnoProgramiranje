#include<stdio.h>
using namespace std;
int main(){
    
    //Poisce najmanjsi skupni veckratni a in b
    
    long long a, b;
    scanf("%lld %lld", &a, &b);
    while(b!=0){
        long long a_novi, b_novi;
        a_novi = b;
        b_novi = a%b;
        
        a = a_novi;
        b = b_novi;
    }
    
    printf("%lld\n", (a*b)/a);
}

// v(a, b) = a*b / D(a, b)

//a  b
//------
//16 12 (16 = 1*12 + 4)
//12 4  (12 = 3*4 + 0)
//4 0

//25 30 (25 = 0*30 + 25)
//30 25 (30 = 1*25 + 5)
//25 5 (25 = 5*5 + 0)
//5 0

//7 5
//35 

// v(a, b) = (a*b)/D(a, b)
// v(16, 12) = (12*16)/4
//          = 48

// v(25, 30) = (25*30)/ 5
            //= 150
