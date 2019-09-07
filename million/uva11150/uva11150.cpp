#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11150"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 200

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN+5];
	memset(table,0,sizeof(table));
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		if( i%2 == 0 )
			table[i] = table[i-1]+2;
		else
			table[i] = table[i-1]+1;
	}

	int num;
	while( ~scanf("%d",&num) )
		printf("%d\n",table[num] );

	return 0;
}