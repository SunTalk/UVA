#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11661"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char load,tmp;
	int num,now,ans;

	while( scanf("%d\n",&num) && num ){

		load = ' ';
		ans = INT_MAX;
		now = 0;
		for(int i = 0 ; i < num ; i++ ){
			
			scanf("%c",&tmp);
			now++;

			if( tmp == 'Z' )
				ans = 0;
			if( tmp == 'R' ){
				if( load == 'D' && now < ans )
					ans = now;
				load = tmp;
				now = 0;
			}
			if( tmp == 'D' ){
				if( load == 'R' && now < ans )
					ans = now;
				load = tmp;
				now = 0;
			}

		}

		printf("%d\n",ans );

	}

	return 0;
}