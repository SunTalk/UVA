#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10071"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int speed,time;
	while( ~scanf("%d %d",&speed,&time) )
		printf("%d\n",speed*time*2 );

	return 0;
}