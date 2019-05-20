#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11000"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long male[105],female[105];
	int num;

	male[0] = 0;
	female[0] = 1;
	for(int i = 1 ; i < 105 ; i++ ){
		male[i] = female[i-1]+male[i-1];
		female[i] = male[i-1]+1;
	}

	while( ~scanf("%d",&num) && num >= 0 )
		printf("%lld %lld\n",male[num],male[num]+female[num] );


	return 0;
}