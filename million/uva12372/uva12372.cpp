#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12372"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int a,b,c;

	for(int k = 1 ; k <= kase ; k++ ){
		scanf("%d %d %d", &a, &b, &c );
		if( a <= 20 && b <= 20 && c <= 20 )
			printf("Case %d: good\n", k );
		else
			printf("Case %d: bad\n", k );
	}

	return 0;
}