#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11636"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[15],i;
	table[0] = 1;
	for( i = 1 ; i < 15 ; i++ )
		table[i] = table[i-1] * 2;

	int num,CASE = 1;
	while( ~scanf("%d",&num) ){
		if( num < 0 )
			break;
		printf("Case %d: ",CASE );
		CASE++;
		for( i = 0 ; i < 15 ; i++ ){
			if( num <= table[i] ){
				printf("%d\n",i );
				break;
			}
		}
	}

	return 0;
}