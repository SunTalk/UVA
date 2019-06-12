#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11172"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	
	int a,b;
	while( CASE-- ){
		scanf("%d %d",&a,&b);
		if( a > b )
			printf(">\n");
		else if( a < b )
			printf("<\n");
		else
			printf("=\n");
	}

	return 0;
}