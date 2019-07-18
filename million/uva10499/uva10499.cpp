#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10499"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long num;

	while( ~scanf("%lld",&num) && num > 0 ){

		if( num == 1 )
			printf("0%\n");
		else
			printf("%lld%\n",num*25 );

	}

	return 0;
}