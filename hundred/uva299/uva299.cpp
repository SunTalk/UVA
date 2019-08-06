#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "299"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int num,table[55];

	while( kase-- ){

		scanf("%d",&num);
		int ans = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&table[i]);
			for(int j = 0 ; j < i ; j++ )
				if( table[j] > table[i] )
					ans++;
		}

		printf("Optimal train swapping takes %d swaps.\n", ans );

	}

	return 0;
}