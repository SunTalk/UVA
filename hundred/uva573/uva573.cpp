#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "573"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double H,U,D,F;

	while( ~scanf("%lf%lf%lf%lf", &H, &U, &D, &F ) && H ){

		int ans = 0;
		double height = 0;
		double tired = U*F/100;

		do{
			ans++;
			height += U;
			if( height > H )
				break;
			U = max(0.0,U-tired);
			height -= D;
		}while( height >= 0 );

		if( height > H )
			printf("success");
		else
			printf("failure");

		printf(" on day %d\n",ans );

	}

	return 0;
}