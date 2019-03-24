#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12004"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long ans[MAXN+5];
	ans[0] = 0;

	for(int i = 1 ; i < MAXN+5 ; i++ )
		ans[i] = ans[i-1] + i;

	int CASE;
	scanf("%d",&CASE);

	int num;
	int times = 1;

	while( CASE-- ){
		printf("Case %d: ", times++ );
		scanf("%d",&num);
		if( ans[num-1]%2 == 0 )
			printf("%lld\n",ans[num-1]/2 );
		else
			printf("%lld/2\n",ans[num-1] );
	}

	return 0;
}