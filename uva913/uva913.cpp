#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "913"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long number;
	while( ~scanf("%lld",&number) ){
		number = (((number+1)*(number+1)/4)*2-3)*3;
		printf("%lld\n",number );
	}

	return 0;
}