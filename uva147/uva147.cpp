#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "147"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double dollar;
	long long table[30005];
	int Currency[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	int tmp,i,j;
	memset(table,0,sizeof(table));

	for( i = 0 ; i < 5 ; i++ )
		table[i] = 1;

	for( i = 0 ; i < 11 ; i++ )
		for( j = 0 ; j < 30005 ; j++ )
			if( j >= Currency[i] )
				table[j] = table[j]+table[j-Currency[i]];
	
	while( ~scanf("%lf",&dollar) && dollar )
		printf("%6.2lf%17lld\n",dollar,table[int(round(dollar*100))] );

	return 0;
}