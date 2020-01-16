#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 20000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

long long table[MAXN+10];

int main(int argc, char const *argv[])
{
	memset(table, 0, sizeof(table));
	for(int i = 2 ; i < MAXN+5 ; i++ ){
		for(int j = i ; j < MAXN+5 ; j+=i )
			table[j] += i;
		table[i] += table[i-1]+1;
	}

	int num;
	while( ~scanf("%d",&num) && num )
		printf("%lld\n", table[num] );


	return 0;
}