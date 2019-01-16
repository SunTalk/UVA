#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "993"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);

	int table[10],i;
	int num;

	while( times-- ){
		
		scanf("%d",&num);
		memset(table,0,sizeof(table));
		if( num < 10 ){
			printf("%d\n",num);
			continue;
		}

		for( i = 9 ; i > 1 ; i-- ){
			while( num % i == 0 ){
				table[i]++;
				num = num/i;
			}
			if( num == 1 )
				break;
		}

		int ans;
		if( num > 1 ){
			printf("-1\n");
			continue;
		}

		for( i = 2 ; i < 10 ; i++ )
			while( table[i]-- )
				printf("%d",i );
		printf("\n");

	}

	return 0;
}