#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "369"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

long long table[MAXN+5][MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	for(int i = 1 ; i < MAXN+5 ; i++ ){
		for(int j = 1 ; j < MAXN+5 ; j++ ){
			if( i == j )
				table[i][j] = 1;
			else if( i > j )
				table[i][j] = table[i-1][j]*i/(i-j);
		}
	}

	int a,b;
	while( ~scanf("%d %d",&a,&b) && a )
		printf("%d things taken %d at a time is %lld exactly.\n", a,b,table[a][b] );

	return 0;
}