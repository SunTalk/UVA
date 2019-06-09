#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10673"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long CASE;
	scanf("%lld",&CASE);

	long long x,k;
	long long floor,ceil;
	long long a,b;

	while( CASE-- ){
		
		scanf("%lld %lld",&x,&k);
		floor = ceil = x/k;
		if( x%k != 0 )
			floor++;

		long long tmp = 0;
		a = 0;
		b = k;

		while( (a*ceil + b*floor) != x )
			a++,b--;

		printf("%lld %lld\n",a,b );

	}

	return 0;
}