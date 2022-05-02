#include <stdio.h>

//5668657576443 24545345

//PREUREDI ISKANJE PRAŠTEVIL

    bool precrtano[1000002];

    long long a = 1000001, b = 1;

    int c, d, e, f;

    int prastevila[77499];

    int main() {

    //ponastavi

    for(long long i = 0;i<a;i++){

        precrtano[i] = false;

    }

 

    //DOLOČITEV PRAŠTEVIL

    for(long long i = 2;i<a;i++){

        if(precrtano[i] == false){

            //if(990000<= i){printf("%lld\n", i);}

            prastevila[b]=i;

            b++;

            for(long long j = 2*i;j<a;j+=i){precrtano[j]=true;}

        }

    }

 

    //izpis števila: printf("%lld", b);

 

    /*//IZPIS PRAŠTEVIL

    for(long long j = 1; j<b;j++){

        printf("%lld %d\n", j, prastevila[j]);

    }//*/

 

    scanf("%d", &c);

    for(int i = 0;i<c;i++){

        scanf("%d", &d);

        e = 1;

        for(int j = 1;prastevila[j]<d;j++){

            if(precrtano[d-prastevila[j]]==false){printf("%d %d\n", prastevila[j], d-prastevila[j]);break;}

        }

    }//*/

 

 

 

    //printf("%lld end\n", b);

    return 0;

}
