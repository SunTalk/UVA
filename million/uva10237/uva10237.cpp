#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10237"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define N 35

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif


	long long Odd[N][N*N],Even[N][N*N];
	long long ans,bishop,number;
	long long len,i,j;

	while( ~scanf("%lld %lld",&bishop,&number) ){

		if( !bishop && !number )
			break;

		memset(Odd,0,sizeof(Odd));
		memset(Even,0,sizeof(Even));

		Odd[0][0] = 1;

		for( i = 1 ; i <= bishop ; i++ ){

			Odd[i][0] = 1;
			len = (i+1)/2 * 2 - 1;

			for( j = 1 ; j <= len && j <= number ; j++ ){
				Odd[i][j] = Odd[i-1][j] + Odd[i-1][j-1]*(len-(j-1));
			}
		}
		
		Even[0][0] = Even[1][0] = 1;

		for( i = 2 ; i <= bishop ; i++ ){

			Even[i][0] = 1;
			len = i/2 * 2;

			for( j = 1 ; j <= len && j <= number ; j++ ){
				Even[i][j] = Even[i-1][j] + Even[i-1][j-1]*(len-(j-1));
			}
		}

		ans = 0;
		for( i = 0 ; i <= number ; i++ ){
			ans = ans + Odd[bishop][i]*Even[bishop][number-i];
		}

		printf("%lld\n",ans );

	}

	return 0;
}