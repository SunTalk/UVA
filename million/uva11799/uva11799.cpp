#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11799"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE,Case = 1;
	scanf("%d",&CASE);
	int tmp,num,ans;

	while( CASE-- ){

		scanf("%d",&tmp);
		ans = 0;
		for(int i = 0 ; i < tmp ; i++ ){
			scanf("%d",&num);
			if( ans < num )
				ans = num;
		}

		printf("Case %d: %d\n",Case++,ans );
	}

	return 0;
}