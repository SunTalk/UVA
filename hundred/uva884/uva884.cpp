#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "884"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int table[MAXN+5];

void build(){

	for(int i = 0 ; i < MAXN+5 ; i++ )
		table[i] = 1;
	table[0] = table[1] = 0;

	for(int i = 2 ; i < MAXN+5 ; i++ )
		if( table[i] == 1 )
			for(int j = 2 ; j*i < MAXN+5 ; j++ )
				table[i*j] = table[i]+table[j];

	for(int i = 2 ; i < MAXN+5 ; i++ )
		table[i] = table[i] + table[i-1];

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	build();

	int num;
	while( ~scanf("%d",&num) )
		printf("%d\n",table[num] );

	return 0;
}