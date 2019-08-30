#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11461"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN+5];
	memset(table,0,sizeof(table));

	for(int i = 1 ; i*i < MAXN+5 ; i++ )
		table[i*i]++;
	for(int i = 1 ; i < MAXN+5 ; i++ )
		table[i] = table[i]+table[i-1];

	int a,b;
	while( ~scanf("%d %d",&a,&b) && a )
		printf("%d\n", table[b]-table[a-1] );

	return 0;
}