#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11069"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int ans[80],i;
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 2;
	for( i = 4 ; i < 80 ; i++ )
		ans[i] = ans[i-2] + ans[i-3];
	
	int num;
	while( ~scanf("%d",&num) )
		printf("%d\n",ans[num] );

	return 0;
}