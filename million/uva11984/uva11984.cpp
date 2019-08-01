#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11984"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	double a,b;

	for(int k = 1 ; k <= kase ; k++ ){
		scanf("%lf %lf",&a,&b);
		printf("Case %d: %.2lf\n",k,a+b/1.8);
	}

	return 0;
}