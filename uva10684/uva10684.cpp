#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10684"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,tmp,i;
	int list[MAXN+5];

	while( ~scanf("%d",&num) && num ){

		memset(list,0,sizeof(list));
		for( i = 1 ; i <= num ; i++ ){
			scanf("%d",&tmp);
			if( list[i-1] > 0 )
				list[i] = list[i-1] + tmp;
			else
				list[i] = tmp;
		}

		int price = 0;
		for( i = 1 ; i <= num ; i++ )
			if( list[i] > price )
				price = list[i];

		if( price > 0 )
			printf("The maximum winning streak is %d.\n",price );
		else
			printf("Losing streak.\n");

	}

	return 0;
}