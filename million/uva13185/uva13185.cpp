#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "13185"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int table[MAXN+5];
	memset(table,0,sizeof(table));

	for(int i = 1 ; i < MAXN+5 ; i++ )
		for(int j = i+i ; j < MAXN+5 ; j = j+i )
			table[j] += i;

	int num;

	while( CASE-- ){

		scanf("%d",&num);
		if( table[num] == num )
			printf("perfect\n");
		else if( table[num] < num )
			printf("deficient\n");
		else
			printf("abundant\n");

	}

	return 0;
}