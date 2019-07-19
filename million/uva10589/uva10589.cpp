#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10589"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double N,M;
	double a,x,y;

	while( ~scanf("%lf %lf",&N,&a) && N ){

		M = 0;
		for(int i = 0 ; i < N ; i++ ){

			scanf("%lf %lf",&x,&y);
			bool check = true;

			if( (x*x + y*y) > (a*a) )
				check = false;
			if( ((x-a)*(x-a) + y*y) > (a*a) )
				check = false;
			if( (x*x + (y-a)*(y-a)) > (a*a) )
				check = false;
			if( ((x-a)*(x-a) + (y-a)*(y-a)) > (a*a) )
				check = false;
			if( check )
				M++;

		}

		double ans = (M/N)*a*a;
		printf("%.5lf\n", ans );

	}


	return 0;
}