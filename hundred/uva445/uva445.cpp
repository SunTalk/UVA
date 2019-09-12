#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "445"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char str;
	int num = 0;

	while( ~scanf("%c",&str) ){

		if( isdigit(str) )
			num += (str-'0');
		else if( str == '!' || str == '\n')
			printf("\n");
		else if( str == 'b' ){
			while( num-- )
				printf(" ");
			num = 0;
		}
		else if( isgraph(str) ){
			while( num-- )
				printf("%c", str);
			num = 0;
		}

	}

	return 0;
}