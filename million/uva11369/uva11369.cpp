#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11369"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 20000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int table[MAXN+5];
	int num;

	while( CASE-- ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		sort(&table[0],&table[num]);

		int ans = 0;
		for(int i = num-3 ; i >= 0 ; i = i-3 )
			ans += table[i];

		printf("%d\n",ans );

	}

	return 0;
}