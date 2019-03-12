#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11389"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int day[105];
	int night[105];
	int num,d,r,i;

	while( scanf("%d %d %d",&num,&d,&r) && (num||d||r) ){

		memset(day,0,sizeof(day));
		memset(night,0,sizeof(night));

		for( i = 0 ; i < num ; i++ )
			scanf("%d",&day[i]);
		for( i = 0 ; i < num ; i++ )
			scanf("%d",&night[i]);
		
		sort(day,day+num);
		sort(night,night+num);

		int ans = 0;
		int tmp;

		for( i = 0 ; i < num ; i++ ){
			tmp = num-i-1;
			tmp = day[i]+night[tmp];
			tmp = tmp - d;
			if( tmp > 0 )
				ans = ans + tmp*r;
		}

		printf("%d\n",ans );

	}

	return 0;
}