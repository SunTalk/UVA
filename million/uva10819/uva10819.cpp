#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10819"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int budget,kind;
	int bag[12005][2],i,j;

	while( ~scanf("%d %d",&budget,&kind) ){
		if( budget > 1800 )
			budget = budget + 200;
		memset(bag,0,sizeof(bag));

		int weight,value;
		for( i = 0 ; i < kind ; i++ ){
			scanf("%d %d",&weight,&value);
			for( j = 1 ; j <= budget ; j++ )
				if( j >= weight )
					bag[j][1] = max( bag[j][0] , bag[j-weight][0] + value );
			for( j = 1 ; j <= budget ; j++ )
				bag[j][0] = bag[j][1];
		}

		int check = budget;
		while( check > 0 && bag[check] == bag[check-1] )
			check--;
		if( check <= 2000 && budget > 2000 )
			printf("%d\n",bag[budget-200][1] );
		else
			printf("%d\n",bag[budget][1] );

	}

	return 0;
}