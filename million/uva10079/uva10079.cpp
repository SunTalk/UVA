#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10079"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long num,ans;
	while( ~scanf("%lld",&num) && num >= 0 ){
		ans = num*(num+1)/2;
		printf("%lld\n",ans+1 );
	}

	return 0;
}