#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10110"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long num,tmp;

	while( ~scanf("%lld",&num) && num ){

		tmp = sqrt(num);
		if( tmp*tmp == num )
			printf("yes\n");
		else
			printf("no\n");

	}

	return 0;
}