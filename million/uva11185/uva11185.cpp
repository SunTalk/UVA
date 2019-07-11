#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11185"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	stack <int> ternary;

	while( ~scanf("%d",&num) && num >= 0 ){

		if( num == 0 )
			printf("0");

		while( num > 0 ){
			ternary.push(num%3);
			num /= 3;
		}

		while( !ternary.empty() ){
			printf("%d",ternary.top() );
			ternary.pop();
		}
		printf("\n");

	}

	return 0;
}