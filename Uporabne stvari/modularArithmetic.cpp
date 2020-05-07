#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 200043;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int fact[N];

int C(int n, int k)
{
	return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}


int main(){
    fact[0] = 1;
	for(int i = 1; i <= N; i++)
		fact[i] = mul(i, fact[i - 1]);
}