#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "108"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int matrix[105][105];
	int sizes,i,j;
	int value,m,n;

	while( ~scanf("%d",&sizes )	){

		memset(matrix,0,sizeof(matrix));
	
		for( i = 1 ; i <= sizes ; i++ ){
			for( j = 1 ; j <= sizes ; j++ ){
				scanf("%d",&value);
				matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + value;
			}
		}
	
		int MAX = -128;
		for( i = 1 ; i <= sizes ; i++ ){
			for( j = 1 ; j <= sizes ; j++ ){
				for( m = 1 ; m <= sizes ; m++ ){
					for( n = 1 ; n <= sizes ; n++ ){
						if( m < i || n < j )
							continue;
						value = matrix[m][n] - matrix[m][j-1] - matrix[i-1][n] + matrix[i-1][j-1];
						if( value > MAX )
							MAX = value;
					}
				}
			}
		}
	
		printf("%d\n",MAX );

	}

	return 0;
}