#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10783"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int sum[105];
	memset(sum,0,sizeof(sum));

	for(int i = 1 ; i < 105 ; i++ ){
		if( i%2 == 1 )
			sum[i] = sum[i-1] + i;
		else
			sum[i] = sum[i-1];
	}

	int TIMES;
	scanf("%d",&TIMES);
	int a,b,count = 1;

	while( TIMES-- ){
		scanf("%d %d",&a,&b);
		if( a == 0 )
			a++;
		printf("Case %d: %d\n",count++,sum[b]-sum[a-1] );
	}

	return 0;
}