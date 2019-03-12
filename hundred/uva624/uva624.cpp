#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "624"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int lengh,number;
	int i,j;

	while( ~scanf("%d %d",&lengh,&number) ){

		int kind[number+1];
		memset(kind,0,sizeof(0));
		for( i = 1 ; i <= number ; i++ )
			scanf("%d",&kind[i]);

		int bag[lengh+1][number+1];
		memset(bag,0,sizeof(bag));

		for( i = 1 ; i <= number ; i++ )
			for( j = 1 ; j <= lengh ; j++ ){
				if( j >= kind[i] )
					bag[j][i] = max( bag[j][i-1] , bag[j-kind[i]][i-1] + kind[i] );
				else
					bag[j][i] = bag[j][i-1];
			}

		j = lengh;
		for( i = number ; i > 0 ; i-- ){
			if( bag[j][i] == bag[j][i-1] )
				kind[i] = 0;
			else
				j = j - kind[i];
		}

		for( i = 0 ; i <= number ; i++ )
			if( kind[i] != 0 )
				printf("%d ",kind[i] );

		printf("sum:%d\n",bag[lengh][number] );

	}

	return 0;
}