#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "406"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	bool table[MAXN+5];
	for(int i = 0; i < MAXN+5 ; i++ )
		table[i] = true;

	for(int i = 2; i < MAXN+5 ; i++ )
		if( table[i] )
			for(int j = i+i ; j < MAXN+5 ; j+=i )
				table[j] = false;

	table[1] = true;
	vector <int> prime;
	for(int i = 1 ; i < MAXN+5 ; i++ )
		if( table[i] )
			prime.push_back(i);

	int N,C;
	while( ~scanf("%d %d",&N,&C) ){

		int len = 0;
		for(int i = 0 ; i < prime.size() ; i++ )
			if( prime[i] <= N )
				len++;

		printf("%d %d:",N,C);
		int k = 0;
		// printf("%d %d\n",k,len);
		if( len%2 && (C*2-1) <= len )
			k = (len-(C*2-1))/2;
		else if( !(len%2) && (C*2) <= len )
			k = (len-(C*2))/2;

		// printf("%d %d\n",k,len);
		for(int i = k ; i < len-k ; i++ )
			printf(" %d",prime[i]);
		printf("\n\n");

	}

	return 0;
}