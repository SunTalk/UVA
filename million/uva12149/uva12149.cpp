#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12149"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN+5];
	table[0] = 0;

	for(int i = 1 ; i < MAXN+5 ; i++ )
		table[i] = table[i-1] + i*i;

	int num;
	while( ~scanf("%d",&num) && num )
		printf("%d\n",table[num] );
	
	return 0;
}