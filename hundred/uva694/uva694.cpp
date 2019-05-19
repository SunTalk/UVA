#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "694"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int start,limit;
	int CASE = 1;

	while( scanf("%d %d",&start,&limit) ){
		
		if( start < 0 && limit < 0 )
			break;

		int ans = 1;
		int tmp = start;

		while( tmp != 1 ){

			if( tmp%2 == 0 )
				tmp = tmp/2;
			else if( tmp > (limit-1)/3 )
				break;
			else
				tmp = tmp*3 + 1;

			ans++;
		}

		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", CASE++,start,limit,ans);

	}

	return 0;
}