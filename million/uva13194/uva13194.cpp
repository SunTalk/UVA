#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "13194"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	long long num,tmp;

	while( CASE-- ){

		scanf("%lld",&num);

		tmp = 1;
		for(long long i = 2 ; i <= sqrt(num) ; i++ ){
			if( num%i == 0 ){
				tmp = tmp+i;
				tmp = tmp+(num/i);
			}
		}
	
		if( tmp == num )
			printf("perfect\n");
		else if( tmp < num )
			printf("deficient\n");
		else
			printf("abundant\n");

	}

	return 0;
}