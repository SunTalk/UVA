#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10699"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int table[MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	memset(table,0,sizeof(table));

	for(int i = 2 ; i < MAXN+5 ; i++ )
		if( table[i] == 0 )
			for(int j = i ; j < MAXN+5 ; j = j+i )
				table[j]++;

	int num;
	while( ~scanf("%d",&num) && num )
		printf("%d : %d\n",num,table[num] );

	return 0;
}