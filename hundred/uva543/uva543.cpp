#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "543"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	bool prime[MAXN+5];
	memset(prime,0,sizeof(prime));
	prime[0] = prime[1] = true;

	for(int i = 2 ; i < MAXN+5 ; i++ )
		if( !prime[i] )
			for(int j = i+i ; j < MAXN+5 ; j += i )
				prime[j] = true;

	int num;
	while( ~scanf("%d",&num) && num ){
		
		bool F = false;
		int ans;
		for( ans = 2 ; ans <= num/2 ; ans++ ){
			if( !prime[ans] ){
				if( !prime[num-ans] ){
					F = true;
					break;
				}
			}
		}

		if( F )
			printf("%d = %d + %d\n", num, ans, num-ans );
		else
			printf( "Goldbach's conjecture is wrong.\n" );

	}

	return 0;
}