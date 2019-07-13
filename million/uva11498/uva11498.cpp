#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11498"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int x,y,a,b;

	while( ~scanf("%d",&num) && num ){

		scanf("%d %d",&x,&y);

		for(int i = 0 ; i < num ; i++ ){
			
			scanf("%d %d",&a,&b);

			if( x == a || y == b )
				printf("divisa\n");
			else if( a < x && b > y )
				printf("NO\n");
			else if( a > x && b > y )
				printf("NE\n");
			else if( a > x && b < y )
				printf("SE\n");
			else if( a < x && b < y )
				printf("SO\n");

		}

	}

	return 0;
}