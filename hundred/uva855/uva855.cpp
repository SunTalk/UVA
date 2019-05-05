#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "855"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 50000

int main(int argc, char const *argv[])
{	

	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	int x[MAXN+5],y[MAXN+5];
	int street,avenue,friends;

	while( CASE-- ){
		scanf("%d %d %d",&street,&avenue,&friends);

		for(int i = 0 ; i < friends ; i++ )
			scanf("%d %d",&x[i],&y[i]);

		sort(x,x+friends);
		sort(y,y+friends);

		printf("(Street: %d, Avenue: %d)\n",x[(friends-1)/2],y[(friends-1)/2] );

	}

	return 0;
}