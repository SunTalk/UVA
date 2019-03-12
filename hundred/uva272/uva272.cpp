#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "272"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char symbol;
	bool check=0;

	while( ~scanf("%c",&symbol) ){
		if( symbol == '"' ){
			if( check == 0 ){
				printf("``");
				check = 1;
			}
			else{
				printf("''");
				check = 0;
			}
		}
		else
			printf("%c",symbol );
	}

	return 0;
}