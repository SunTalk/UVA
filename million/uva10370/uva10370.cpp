#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10370"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	int num,total;
	float average,ans;
	int people[1005];

	while( CASE-- ){

		scanf("%d",&num);
		total = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&people[i]);
			total = total + people[i];
		}

		average = total/num;

		ans = 0;
		for(int i = 0 ; i < num ; i++ )
			if( people[i] > average )
				ans++;
		ans = (ans*100)/num;

		printf("%.3f%\n",ans );

	}

	return 0;
}