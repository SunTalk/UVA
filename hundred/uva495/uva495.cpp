#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "495"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 5000
int Fib[MAXN+5][2000];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	memset(Fib,0,sizeof(Fib));
	Fib[1][0] = 1;
	for(int i = 2 ; i < MAXN+5 ; i++ ){
		for(int j = 0 ; j < 2000 ; j++ ){
			Fib[i][j] += (Fib[i-1][j]+Fib[i-2][j]);
			Fib[i][j+1] += Fib[i][j]/10;
			Fib[i][j] %= 10;
		}
	}

	int num,check;
	while( ~scanf("%d",&num) ){
		printf("The Fibonacci number for %d is ",num );
		for(check = 1999 ; check >= 0 ; check-- )
			if( Fib[num][check] )
				break;
		check++;
		if( check == 0 )
			printf("0");
		else
			while( check-- )
				printf("%d",Fib[num][check] );
		printf("\n");
	}

	return 0;
}