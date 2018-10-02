#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12461"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number;
	while( ~scanf("%d",&number) && number)
		printf("1/2\n");

	return 0;
}