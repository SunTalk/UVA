#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11875"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	int num;
	int table[15];
	int Case = 1;
	
	while( CASE-- ){
		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		sort(&table[0],&table[num]);

		printf("Case %d: %d\n",Case++,table[num/2] );

	}

	return 0;
}