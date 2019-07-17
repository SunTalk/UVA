#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10209"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define PI 2.0*acos(0.0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double num,a,b,c;

	while( ~scanf("%lf",&num) ){

		a = num*num - (num*num*PI/6) - (num*num*sqrt(3)/4);
		b = num*num - (num*num*PI/4) - (2*a);
		c = num*num - 4*a - 4*b;

		printf("%.3lf %.3lf %.3lf\n", c, 4*b, 4*a );

	}

	return 0;
}