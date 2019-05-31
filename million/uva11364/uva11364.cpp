#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11364"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	int num,s,b;
	int tmp;

	while( CASE-- ){

		scanf("%d",&num);
		s = INT_MAX;
		b = INT_MIN;
		
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&tmp);
			if( tmp < s )
				s = tmp;
			if( tmp > b )
				b = tmp;
		}

		printf("%d\n", 2*(b-s) );

	}

	return 0;
}