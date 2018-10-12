#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "458"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char symbol;

	while( ~scanf("%c",&symbol) ){
		if(symbol!='\n')
			symbol = symbol - 7;
		printf("%c",symbol);
	}
	

	return 0;
}