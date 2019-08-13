#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "382"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,total,tmp;
	printf("PERFECTION OUTPUT\n");
	
	while( ~scanf("%d",&num) && num ){
		
		tmp = (int)sqrt(num);
		total = 1;

		for(int i = 2 ; i <= tmp ; i++ )
			if( num%i == 0 )
				total += i+num/i;
		if( num == tmp*tmp )
			total -= tmp;

		printf("%5d  ", num);
		if ( total == num )
			printf("PERFECT\n");
		if ( total > num )
			printf("ABUNDANT\n");
		if ( total < num )
			printf("DEFICIENT\n");

	}

	printf("END OF OUTPUT\n");

	return 0;
}