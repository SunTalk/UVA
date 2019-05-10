#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10721"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int units,bars,wides;
	long long table[55][55];

	while( ~scanf("%d %d %d",&units,&bars,&wides) ){

		memset(table,0,sizeof(table));
		table[0][0] = 1;

		for(int i = 1 ; i <= units ; i++ ){
			for(int j = 1 ; j <= bars ; j++ ){
				for(int k = 1 ; k <= wides ; k++){
					if( i >= k )
						table[i][j] = table[i][j] + table[i-k][j-1];
				}
			}
		}

		printf("%lld\n",table[units][bars] );

	}

	return 0;
}