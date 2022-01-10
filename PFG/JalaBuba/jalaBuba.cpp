#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n > 2 && m > 2 && m == n) printf("Jala\n");
    else if (n > 2 && m > 2 && m!=n) printf("Buba\n");
    else if(min(n, m) <= 2 && max(n, m) > 2) printf("Buba\n");
    else if(n == m) printf("Jala\n");
    else printf("Buba\n");
}
