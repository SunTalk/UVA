#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "674"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int coin[8000];
	memset(coin,0,sizeof(coin));
	int value[5] = {1,5,10,25,50};
	int tmp,i,j;

	coin[0] = 1;

	for( i = 0 ; i < 5 ; i++ )
		for( j = 0 ; j < 8000 ; j++ )
			if( j >= value[i] )
				coin[j] = coin[j] + coin[j-value[i]];

	while( ~scanf("%d",&tmp) )
		printf("%d\n", coin[tmp] );

	return 0;
}