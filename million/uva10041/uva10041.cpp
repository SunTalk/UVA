#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10041"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int num,table[505];
	int home,ans;

	while( kase-- ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);
		sort(&table[0],&table[num]);

		if( num%2 )
			home = table[num/2];
		else
			home = (table[(num/2)-1]+table[num/2])/2;

		ans = 0;
		for(int i = 0 ; i < num ; i++ )
			ans += abs(home-table[i]);

		printf("%d\n",ans );

	}

	return 0;
}