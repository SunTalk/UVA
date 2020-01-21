#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN+10];

int main(int argc, char const *argv[])
{
	long long ans = 1;
	table[0] = 1;
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		ans *= i;
		while( ans%10 == 0 )
			ans /= 10;
		table[i] = ans%10;
		ans %= 1000000;
	}

	int num;
	while( ~scanf("%d",&num) )
		printf("%5d -> %d\n",num,table[num]);

	return 0;
}