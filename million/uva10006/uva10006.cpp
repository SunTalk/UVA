#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 65000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

LL POW_MOD(LL a, LL n, LL m){
	if( n == 0 ) return 1;
	if( n == 1 ) return a;
	LL k = POW_MOD(a,n/2,m);
	k = ((k%m)*(k%m))%m;
	if( n&1 ) k = (k*a)%m;
	return k;
}

bool Fermat(int n){
	for(int i = 2 ; i < n ; i++ )
		if( POW_MOD((LL)i, (LL)n, (LL)n) != (LL)i )
			return false;
	return true;
}

bool prime[MAXN+10];

void build(){
	for(int i = 0 ; i < MAXN+5 ; i++ )
		prime[i] = true;
	for(int i = 2 ; i < MAXN+5 ; i++ )
		if( prime[i])
			for(int j = i+i ; j < MAXN+5 ; j+=i )
				prime[j] = false;
}

int main(int argc, char const *argv[])
{

	build();

	int num;
	while( ~scanf("%d",&num) && num ){
		if( ! prime[num] && Fermat(num) )
			printf("The number %d is a Carmichael number.\n",num);
		else
			printf("%d is normal.\n",num);
	}

	return 0;
}