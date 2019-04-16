#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10696"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	while( ~scanf("%d",&num) && num ){
		if( num > 100 )
			printf("f91(%d) = %d\n", num, num-10 );
		else
			printf("f91(%d) = 91\n", num);
	}

	return 0;
}