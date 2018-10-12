#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "494"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char symbol;
	int number=0;

	while( ~scanf("%c",&symbol) ){
		if( isalpha(symbol) ){
			while( scanf("%c",&symbol) ){
				if( !isalpha(symbol) ){
					if( symbol == '\n' ){
						printf("%d\n",number+1 );
						number = 0;
					}
					number++;
					break;
				}
			}
		}
		else if( symbol == '\n' ){
			printf("%d\n",number );
			number = 0;
		}

	}

	return 0;
}