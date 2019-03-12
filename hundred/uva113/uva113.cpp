#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "113"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double K,P,N;

	while(scanf("%lf %lf",&N,&P) != EOF){
		K=pow(P,(1/N));
		printf("%.0lf\n",K);
	}

	return 0;
}