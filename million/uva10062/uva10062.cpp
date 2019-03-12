#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10062"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int Ascii[130];
	char symbol;
	int max,i,j;
	memset(Ascii,0,sizeof(Ascii));
	max = 0;
	bool enter = 0;

	while( ~scanf("%c",&symbol) ){

		if( symbol == '\n'){

			if( enter == 1 )
				printf("\n");

			for( i = 1 ; i <= max ; i++ ){
				for( j = 130 ; j >= 0 ; j-- ){
					if( Ascii[j] == i )
						printf("%d %d\n", j,i);
				}
			}

			memset(Ascii,0,sizeof(Ascii));
			max = 0;
			enter = 1;
		}
		else{
			Ascii[symbol]++;
			if( Ascii[symbol] > max )
				max = Ascii[symbol];
		}
	}

	return 0;

}