#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10812"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long a,b;
	long long s,d;
	long long kase;
	scanf("%lld",&kase);

	while( kase-- ){

		scanf("%lld %lld",&s,&d);

		a = (s+d)/2;
		b = s-a;

		if( (s+d)%2 == 1 || b < 0 )
			printf("impossible\n");
		else
			printf("%lld %lld\n",a,b );

	}

	return 0;
}