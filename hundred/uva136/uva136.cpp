#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "136"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	// int ans = 0;
	// for(int i = 1 ; i < INT_MAX ; i++ ){
	// 	int tmp = i;
	// 	while( tmp%2 == 0 )
	// 		tmp = tmp/2;
	// 	while( tmp%3 == 0 )
	// 		tmp = tmp/3;
	// 	while( tmp%5 == 0 )
	// 		tmp = tmp/5;
	// 	if( tmp == 1 )
	// 		ans++;
	// 	if( ans == 1500 ){
	// 		printf("ans%d\n",i );
	// 		break;
	// 	}
	// }

	printf("The 1500'th ugly number is 859963392.\n");

	return 0;
}