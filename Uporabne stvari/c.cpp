#include<math.h>
#include <stdio.h>

float Q_rsqrt(float number) {

    //Definition of auxillary variables
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    x2 = number * 0.5F;
    y = number;
    
    /* 
    * The binary representation of the input
    * variable is shifted by one bit to the right
    * and substracted from the constant 
    * 0x5f3759df = 1597463007
    */
    i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *) &i;
    
    //One iteration of Newton's method
    y = y * (threehalfs - (x2 * y * y));

    return y;
}

float Taylor(float x){

    //Extract the exponent E and the mantissa m
    long i = *(long *) &x;
    int E = (i >> 23) & 0xff;
    int M = i & 0x7fffff;
    float m = M / pow(2, 23);

    //Compute exponent of 1/sqrt(x)
    long E_b;
    float m_b;
    if(E%2==0 or M == 0) E_b = -(E/2) + 190;
    else E_b = -(E/2) + 189;

    //Calculate the mantissa using 2nd degree Taylor polynomial
    if(m == 0 and M%2) m_b = 0;
    else if(M%2) m_b = 0.26192396*m*m - 0.80601962*m + 0.97052017;
    else m_b = (0.26192396*m*m - 0.80601962*m+1.97052017) * 0.70710678118 - 1;

    //Return an approximation for 1/sqrt(x)
    int M_b = m_b * pow(2, 23);
    long res = (E_b << 23) | M_b;
    float res_f = *(float *) &res;
    return res_f;
}

float TaylorNewton(float number){

    //Extract the exponent E and the mantissa m
    long i = *(long *) &x;
    int E = (i >> 23) & 0xff;
    int M = i & 0x7fffff;
    float m = M / pow(2, 23);

    //Compute exponent of 1/sqrt(x)
    long E_b;
    float m_b;
    if(E%2==0 or M == 0) E_b = -(E/2) + 190;
    else E_b = -(E/2) + 189;

    //Calculate the mantissa using 2nd degree Taylor polynomial
    if(m == 0 and M%2) m_b = 0;
    else if(M%2) m_b = 0.26192396*m*m - 0.80601962*m + 0.97052017;
    else m_b = (0.26192396*m*m - 0.80601962*m+1.97052017) * 0.70710678118 - 1;
    
    //Perform one iteration of Newton's method
    m_b = m_b - 0.25*(m_b+1) * ((m_b+1)*(m_b+1)*(m+1) - 2); 

    //Return an approximation for 1/sqrt(x)
    int M_b = m_b * pow(2, 23);
    long res = (E_b << 23) | M_b;
    float res_f = *(float *) &res;
    return res_f;
}

float TaylorNewtonTwice(float number){

    //Extract the exponent E and the mantissa m
    long i = *(long *) &x;
    int E = (i >> 23) & 0xff;
    int M = i & 0x7fffff;
    float m = M / pow(2, 23);

    //Compute exponent of 1/sqrt(x)
    long E_b;
    float m_b;
    if(E%2==0 or M == 0) E_b = -(E/2) + 190;
    else E_b = -(E/2) + 189;

    //Calculate the mantissa using 2nd degree Taylor polynomial
    if(m == 0 and M%2) m_b = 0;
    else if(M%2) m_b = 0.26192396*m*m - 0.80601962*m + 0.97052017;
    else m_b = (0.26192396*m*m - 0.80601962*m+1.97052017) * 0.70710678118 - 1;
    
    //Perform one iteration of Newton's method
    m_b = m_b - 0.25*(m_b+1) * ((m_b+1)*(m_b+1)*(m+1) - 2); 

    //Return an approximation for 1/sqrt(x)
    int M_b = m_b * pow(2, 23);
    long res = (E_b << 23) | M_b;
    float res_f = *(float *) &res;
    return res_f;
}


float TaylorSecant(float number){

    //Extract the exponent E and the mantissa m
    long i = *(long *) &x;
    int E = (i >> 23) & 0xff;
    int M = i & 0x7fffff;
    float m = M / pow(2, 23);

    //Compute exponent of 1/sqrt(x)
    long E_b;
    float m_b;
    if(E%2==0 or M == 0) E_b = -(E/2) + 190;
    else E_b = -(E/2) + 189;

    //Calculate the mantissa using 2nd degree Taylor polynomial
    if(m == 0 and M%2) m_b = 0;
    else if(M%2) m_b = 0.26192396*m*m - 0.80601962*m + 0.97052017;
    else m_b = (0.26192396*m*m - 0.80601962*m+1.97052017) * 0.70710678118 - 1;
    
    //Perform one iteration of Newton's method
    m_b = m_b - 0.25*(m_b+1) * ((m_b+1)*(m_b+1)*(m+1) - 2); 

    
    //Define the lower and upper bound of m_b
    float a = m_b - 0.03;
    float b = m_b + 0.03;

    //Perform one iteration of the secant method
    float fa = 1 + m - 2/((1+a)*(1+a));
    float fb = 1 + m - 2/((1+b)*(1+b));
    m_b = b - fb*(b-a)/(fb-fa);

    //Return an approximation for 1/sqrt(x)
    int M_b = m_b * pow(2, 23);
    long res = (E_b << 23) | M_b;
    float res_f = *(float *) &res;
    return res_f;
}

int main(){

    int i;
    float f;
    double e, max = 0.0;
    
    while(1){
        scanf("%f", &f);
        printf("%.4f %.4f\n", Taylor(f), 1/sqrt(f));
    }
    printf("%f\n%e\n", max, max);
   
    return 0;
}