#include<stdio.h>

int gcd(int a, int b){
	int _a, _b;
	while(b > 0){
		_a = b;
		_b = a%b;
		a = _a;
		b = _b;
	}
	return a;
}

int lcm(int a, int b){
	return (a*b)/gcd(a, b);
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	
	int ljudje[N];
	for(int i=0; i<N; i++){
		scanf("%d", &ljudje[i]);
	}
	
	//Izracunamo LCM (najmanji skupni veckratnik) vseh stevil
	int v = 1;
	for(int i=0; i<N; i++){
		v = lcm(v, ljudje[i]);
	}
	
	printf("%d\n", v);
	
	//Izpisemo najmanjso ceno, ki je enaka (veckratnik v) + 1 in je vecja ali enaka K
	int odgovor = 1;
	while(odgovor < K){
		odgovor += v;
	}
	
	printf("%d\n", odgovor);
}
