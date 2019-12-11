#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	long long table[MAXN] = {0,1,2};
	for(int i = 3 ; i < MAXN ; i++ )
		table[i] = table[i-1] + table[i-2];

	int num;
	while( ~scanf("%d",&num) && num )
		printf("%lld\n",table[num]);

	return 0;
}